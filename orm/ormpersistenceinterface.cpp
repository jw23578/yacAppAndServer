#include "ormpersistenceinterface.h"
#include "JWUtils/extuuid.h"
#include "orm_implementions/t0035_blobs.h"

ORMPersistenceInterface::ORMPersistenceInterface(ORMSqlInterface &sqlInterface):sqlInterface(sqlInterface) {}

bool ORMPersistenceInterface::insertObject(ORMObjectInterface &object, const reducedsole::uuid &created_by_t0003_id) const
{
    object.setUuid("id", ExtUuid::generateUuid());
    object.setUuid("created_by_t0003_id", created_by_t0003_id);
    SqlString sqlHistoried;
    sqlHistoried.update(MACRO_ORM_STRING_2_STD_STRING(object.getORMName()));
    sqlHistoried.addSet("historied", "now()", false);
    sqlHistoried.addCompare("where", "historied", "is", TimePointPostgreSqlNull);
    const auto &p(object.getIDProperty());
    sqlHistoried.addCompare("and", p->name(), "=", p->asString());
    sqlInterface.execute(sqlHistoried);

    SqlString sql;
    sql.insert(MACRO_ORM_STRING_2_STD_STRING(object.getORMName()));
    for (const auto &p: object.getProperties())
    {
        if (p->hasDetail(DetailDB))
        {
            sql.addInsert(MACRO_ORM_STRING_2_STD_STRING(p->name()), p->asString(), p->isNull());
        }
    }
    return sqlInterface.execute(sql);
}

bool ORMPersistenceInterface::existObject(const ORMUuid &id, ORMObjectInterface const &target)
{
    SqlString sql;
    sql.select("id", MACRO_ORM_STRING_2_STD_STRING(target.getORMName()));
    ORMPropertyInterface *p(target.getIDProperty());
    sql.addCompare("where", MACRO_ORM_STRING_2_STD_STRING(p->name()), "=", MACRO_ORM_STRING_2_STD_STRING(id));
    sql.addCompare("and", "historied", "is", TimePointPostgreSqlNull);
    sql.addCompare("and", "deleted", "is", TimePointPostgreSqlNull);
    if (!sqlInterface.open(sql))
    {
        return false;
    }
    return true;
}

bool ORMPersistenceInterface::selectObject(const ORMUuid &id, ORMObjectInterface &target)
{
    size_t ignore(0);
    return selectObject(id, target, ignore);
}


bool ORMPersistenceInterface::selectObject(const ORMUuid &id, ORMObjectInterface &target, size_t &count)
{
    SqlString sql;
    sql.select(MACRO_ORM_STRING_2_STD_STRING(target.getORMName()));
    ORMPropertyInterface *p(target.getIDProperty());
    sql.addCompare("where", MACRO_ORM_STRING_2_STD_STRING(p->name()), "=", MACRO_ORM_STRING_2_STD_STRING(id));
    sql.addCompare("and", "historied", "is", TimePointPostgreSqlNull);
    sql.addCompare("and", "deleted", "is", TimePointPostgreSqlNull);
    if (!sqlInterface.open(sql))
    {
        count = 0;
        return false;
    }
    count = sqlInterface.size();
    target.fill(sqlInterface);
    return true;
}

bool ORMPersistenceInterface::selectObject(std::map<ORMString, ORMString> field2needle,
                                           ORMObjectInterface &target)
{
    size_t ignore(0);
    return selectObject(field2needle, target, ignore);
}

bool ORMPersistenceInterface::selectObject(std::map<ORMString, ORMString> field2needle,
                                           ORMObjectInterface &target,
                                           size_t &count)
{
    SqlString sql;
    sql.select(MACRO_ORM_STRING_2_STD_STRING(target.getORMName()));
    bool first(true);
    for (const auto &f2n: field2needle)
    {
        sql.addCompare(first ? "where" : "and", MACRO_ORM_STRING_2_STD_STRING(f2n.first), "=", MACRO_ORM_STRING_2_STD_STRING(f2n.second));
        first = false;
    }
    sql.addCompare(first ? "where" : "and", "historied","is", TimePointPostgreSqlNull);
    sql.addCompare("and", "deleted","is", TimePointPostgreSqlNull);
    if (!sqlInterface.open(sql))
    {
        count = 0;
        return false;
    }
    count = sqlInterface.size();
    target.fill(sqlInterface);
    return true;
}

bool ORMPersistenceInterface::deleteObject(ORMObjectInterface &object, reducedsole::uuid const &deleted_by_t0003_id)
{
    SqlString sqlDeleted;
    sqlDeleted.update(MACRO_ORM_STRING_2_STD_STRING(object.getORMName()));
    sqlDeleted.addSet("deleted", "now()", false);
    sqlDeleted.addSet("deleted_by_t0003_id", deleted_by_t0003_id, false);
    sqlDeleted.addCompare("where", "historied", "is", TimePointPostgreSqlNull);
    const auto &p(object.getIDProperty());
    sqlDeleted.addCompare("and", p->name(), "=", p->asString());
    return sqlInterface.execute(sqlDeleted);
}

bool ORMPersistenceInterface::sameDataExists(ORMObjectInterface &object) const
{
    SqlString sql("select id from ");
    sql += MACRO_ORM_STRING_2_STD_STRING(object.getORMName());

    bool firstCompare(true);
    for (const auto &p: object.getProperties())
    {
        if (p->hasDetail(DetailDB) && !p->hasDetail(DetailDBPrimaryKey) && !p->hasDetail(DetailID) && !p->hasDetail(DetailDBSystemInfo))
        {
            sql.addCompare(firstCompare ? "where" : "and", MACRO_ORM_STRING_2_STD_STRING(p->name()), "=", MACRO_ORM_STRING_2_STD_STRING(p->asString()));
            firstCompare = false;
        }
    }
    sql += " limit 1";
    sqlInterface.open(sql);
    if (sqlInterface.size() > 0)
    {
        object.setUuid("id", sqlInterface.uuidValue("id").value());
        return true;
    }
    return false;
}

bool ORMPersistenceInterface::insertIfNotSameDataExists(ORMObjectInterface &object, const reducedsole::uuid &created_by_t0003_id) const
{
    if (sameDataExists(object))
    {
        return true;
    }
    return insertObject(object, created_by_t0003_id);
}

size_t ORMPersistenceInterface::fetchIDs(const SqlString &sql,
                                         std::set<ORMUuid> &ids)
{
    if (!sqlInterface.open(sql))
    {
        return 0;
    }
    for (size_t i(0); i < sqlInterface.size(); ++i)
    {
        std::string s(sqlInterface.value("id").value_or(""));
        if (s.size())
        {
            ids.insert(ExtUuid::stringToUuid(MACRO_STD_STRING_2_ORM_STRING(s)));
        }
        sqlInterface.next();
    }
    return ids.size();
}

ORMUuid ORMPersistenceInterface::storeBlob(const std::basic_string<std::byte> &data, const reducedsole::uuid &created_by_t0003_id)
{
    t0035_blobs t0035;
    t0035.setid(ExtUuid::generateUuid());
    t0035.setblob_oid(sqlInterface.storeBlob(data));
    insertObject(t0035, created_by_t0003_id);
    return t0035.getid();
}

bool ORMPersistenceInterface::fetchBlob(const ORMUuid &blobUuid, std::basic_string<std::byte> &data)
{
    t0035_blobs t0035;
    if (!selectObject(blobUuid, t0035))
    {
        return false;
    }
    return sqlInterface.fetchBlob(t0035.getblob_oid(), data);
}

bool ORMPersistenceInterface::deleteBlob(const ORMUuid &blobUuid, const reducedsole::uuid &deleted_by_t0003_id)
{
    t0035_blobs t0035;
    if (!selectObject(blobUuid, t0035))
    {
        return false;
    }
    deleteObject(t0035, deleted_by_t0003_id);
    return true;

}
