#ifndef YACBASEOBJECT_H
#define YACBASEOBJECT_H

#include "orm/ormobjectinterface.h".h"
#include "rightnumbers.h"
#include "tablefields.h"

#define MACRO_ADD_INDEX_PROPERTY(name) \
    MACRO_ADD_PROPERTY(name); \
    propertyNamesToHaveAnIndex.insert(#name);

class YACBaseObject : public ORMObjectInterface
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif


    MACRO_UUID_PROPERTY(id);
protected:
    std::set<ORMString> propertyNamesToHaveAnIndex;
public:
    const RightNumber changeRight;


    YACBaseObject(RightNumber changeRight):ORMObjectInterface(),
        changeRight(changeRight)
    {
        MACRO_ADD_PROPERTY(id);
    }
    bool shouldBeIndexed(const ORMString &propertyName) const;

    void assign(const YACBaseObject &other);
};

#endif // YACBASEOBJECT_H
