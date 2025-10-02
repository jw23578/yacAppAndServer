#include "appbaseobject.h"
#include "ormpersistenceinterface.h"


void AppBaseObject::erase(CurrentContext &context)
{
    context.opi.deleteObject(*this, context.userId);
}

void AppBaseObject::store(CurrentContext &context)
{
    app_id = context.appId;
    prepareFirstInsert();
    context.opi.insertObject(*this, context.userId);
}

void AppBaseObject::storeIfUnique(CurrentContext &context)
{
    app_id = context.appId;
    prepareFirstInsert();
    context.opi.insertIfNotSameDataExists(*this, context.userId);
}

bool AppBaseObject::load(CurrentContext &context,
                         const reducedsole::uuid &id)
{
    size_t count(0);
    return context.opi.selectObject({{getIDProperty()->name(), id.str()}},
                                    app_id.name(), context.appId.str(),
                                    *this) && count == 1;
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
    return context.opi.selectObject(field2needle, app_id.name(), context.appId.str(), *this, count) && count == 1;
}
