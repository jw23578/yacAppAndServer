#ifndef ORMOBJECTINTERFACE_H
#define ORMOBJECTINTERFACE_H

#include <set>
#include <map>
#include "ormdefinitions.h"
#include "ormpropertyinterface.h"


class ORMObjectInterface
{
    std::map<ORMString, ORMPropertyInterface*> properties;
    void addProperty(ORMString propertyName, ORMPropertyInterface &property);
public:
    ORMObjectInterface();

    ORMString getValueToString(const ORMString &propertyName) const;
    void setValueFromString(const ORMString &propertyName,
                            const ORMString &value);

    void getPropertyNames(std::set<ORMString> &propertyNames);
};

#endif // ORMOBJECTINTERFACE_H
