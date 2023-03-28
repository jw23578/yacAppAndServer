#ifndef ORMOBJECTINTERFACE_H
#define ORMOBJECTINTERFACE_H

#include <set>
#include <map>
#include "ormdefinitions.h"
#include "ormpropertyinterface.h"
#include "ormpropertysizet.h"
#include "ormpropertyuuid.h"
#include "ormpropertystring.h"

class ORMObjectInterface
{
    std::map<ORMString, ORMPropertyInterface*> properties;
protected:
    void addProperty(ORMString propertyName, ORMPropertyInterface &property);
public:
    ORMObjectInterface();
    virtual const ORMString getORMName() const = 0;

    ORMString getValueToString(const ORMString &propertyName) const;
    void setValueFromString(const ORMString &propertyName,
                            const ORMString &value);

    void getPropertyNames(std::set<ORMString> &propertyNames);
};

#endif // ORMOBJECTINTERFACE_H
