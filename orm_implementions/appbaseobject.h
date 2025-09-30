#ifndef APPBASEOBJECT_H
#define APPBASEOBJECT_H

#include "yacbaseobject.h"
#include "currentcontext.h"
#include "logstatcontroller.h"

class AppBaseObject : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
public:
    AppBaseObject(const RightNumber changeRight):YACBaseObject(changeRight)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
    }
    void erase(CurrentContext &context);
    void store(CurrentContext &context);
    void storeIfUnique(CurrentContext &context);
    bool load(CurrentContext &context,
              const reducedsole::uuid &id);
    bool load(CurrentContext &context,
              const std::map<ORMString, ORMString> &field2needle);
};

#endif // APPBASEOBJECT_H
