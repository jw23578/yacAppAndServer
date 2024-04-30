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

#endif // YACBASEOBJECT_H
