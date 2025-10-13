#include "t0022_right_group2user.h"
#include "t0021_right_group.h"
#include "t0023_right2rightgroup.h"

bool t0022_right_group2user::removeUser(CurrentContext &context,
                                           const ORMUuid &rightGroupId,
                                           const ORMUuid &userId,
                                           std::string &message)
{
    if (!userInRightGroup(context, rightGroupId, userId))
    {
        message = "user is not in rightgroup";
        return false;
    }
    erase(context);
    return true;
}

bool t0022_right_group2user::userInRightGroup(CurrentContext &context,
                                              const ORMUuid &rightGroupId,
                                              const ORMUuid &userId)
{
    return load(context,
              {{right_group_idORM().name(), ExtUuid::uuidToString(rightGroupId)},
               {user_idORM().name(), ExtUuid::uuidToString(userId)}});
}


void t0022_right_group2user::fetchUserRightNumbers(CurrentContext &context,
                                                      const ORMUuid &userId,
                                                      std::set<int> &rightNumbersSet)
{
    SqlString sql;
    sql.select(t0023_right2rightgroup().getORMName());
    sql += ORMString(" where ") + right_group_idORM().name();
    sql += ORMString(" in (select ") + right_group_idORM().name();
    sql += ORMString(" from ") + getORMName();
    sql.addCompare("where", user_idORM().name(), "=", ExtUuid::uuidToString(userId));
    sql.addCompare("and", app_idORM().name(), "=", context.appId);
    context.opi.addOnlyInsertDBWhere(false, sql);
    sql += ORMString(")");
    context.opi.addOnlyInsertDBWhere(false, sql);
    context.opi.fetchValues(sql, t0023_right2rightgroup().right_numberORM().name(), rightNumbersSet);
}

bool t0022_right_group2user::adminExists(CurrentContext &context, const ORMString &adminGroupName)
{
    SqlString sql;
    sql.select(t0022_right_group2user().getORMName());
    sql += ORMString(" where ") + right_group_idORM().name() + ORMString(" = (");
    sql += ORMString("select ") + right_group_idORM().name() + ORMString(" from ") + t0021_right_group().getORMName();
    sql.addCompare("where", t0021_right_group().nameORM().name(), "=", adminGroupName);
    sql.addCompare("and", app_idORM().name(), "=", context.appId);
    context.opi.addOnlyInsertDBWhere(false, sql);
    sql += ORMString(" ) ");
    sql.addCompare("and", app_idORM().name(), "=", context.appId);
    context.opi.addOnlyInsertDBWhere(false, sql);
    sql += ORMString(" limit 1");
    size_t count(0);
    context.opi.selectObject(sql, *this, count);
    return count > 0;
}
