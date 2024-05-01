#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h"
#include "rightnumbers.h"
#include "tablefields.h"

#define MACRO_ADD_INDEX_PROPERTY(name) \
    MACRO_ADD_PROPERTY(name); \
    propertyNamesToHaveAnIndex.insert(#name);

#define MACRO_ADD_TRANSFER_PROPERTY(name) \
    MACRO_ADD_PROPERTY(name); \
    transferProperties.insert(#name);

#define MACRO_ADD_NOTRANSFER_PROPERTY(name) \
    MACRO_ADD_PROPERTY(name); \
    noTransferProperties.insert(#name);

#define MACRO_CREATE_AND_GETORMNAME(name) \
const ORMString getORMName() const override \
{ \
return #name; \
} \
YACBaseObject *create() const override \
{ \
    return new name; \
}


class YACBaseObject : public ORMObjectInterface
{
MACRO_CPP_OR_Q_OBJECT

    MACRO_UUID_PROPERTY(id);
protected:
    std::set<ORMString> propertyNamesToHaveAnIndex;
    std::set<ORMString> transferProperties;
    std::set<ORMString> noTransferProperties;
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
    }
    bool shouldBeIndexed(const ORMString &propertyName) const;
    bool isTransferProperty(const ORMString &propertyName) const;

    void assign(const YACBaseObject &other);
};

#define MACRO_BEGIN_APP_ORM_OBJECT(name) \
class name : public YACBaseObject \
{ \
MACRO_CPP_OR_Q_OBJECT \
MACRO_UUID_PROPERTY(app_id); \
public: \
MACRO_CREATE_AND_GETORMNAME(name) \
private:



#endif // YACBASEOBJECT_H
