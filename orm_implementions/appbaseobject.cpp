#include "appbaseobject.h"
#include "ormpersistenceinterface.h"


void AppBaseObject::setTheAppId(const CurrentContext &context)
{
    if (!app_idORM().isNull() && app_idORM().get() != NullUuid)
    {
        return;
    }
    setapp_id(context.appId);
}

void AppBaseObject::erase(CurrentContext &context)
{
    context.opi.deleteObject(*this, context.userId);
}

void AppBaseObject::store(CurrentContext &context)
{
    setTheAppId(context);
    prepareFirstInsert();
    context.opi.insertObject(*this, context.userId);
}

void AppBaseObject::storeIfUnique(CurrentContext &context)
{
    setTheAppId(context);
    prepareFirstInsert();
    context.opi.insertIfNotSameDataExists(*this, context.userId);
}

bool AppBaseObject::load(CurrentContext &context,
                         const ORMUuid &id)
{
    if (context.ignoreAppId())
    {
        return context.opi.selectObject({{getIDProperty()->name(), ExtUuid::uuidToString(id)}},
                                        *this);
    }
    return context.opi.selectObject({{getIDProperty()->name(), ExtUuid::uuidToString(id)}},
                                    app_idORM().name(),
                                    ExtUuid::uuidToString(context.appId),
                                    *this);
}

bool AppBaseObject::load(CurrentContext &context,
                         const ORMPropertyUuid &puuid)
{
    return load(context, {{puuid.name(), puuid.asString()}});
}

bool AppBaseObject::load(CurrentContext &context,
                         const std::map<ORMString, ORMString> &field2needle)
{
    size_t count(0);
    return context.opi.selectObject(field2needle, app_idORM().name(), ExtUuid::uuidToString(context.appId), *this, count) && count == 1;
}
