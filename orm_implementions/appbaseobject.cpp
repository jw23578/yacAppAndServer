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
    return context.opi.selectObject({{getIDProperty()->name(), id.str()}},
                                    app_id.name(), context.appId.str(),
                                    *this);
}

bool AppBaseObject::load(CurrentContext &context,
                         const std::map<ORMString, ORMString> &field2needle)
{
    return context.opi.selectObject(field2needle, app_id.name(), context.appId.str(), *this);
}
