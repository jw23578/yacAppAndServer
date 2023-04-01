#ifndef ORMOBJECTINTERFACE_H
#define ORMOBJECTINTERFACE_H

#include <set>
#include <map>
#include "ormdefinitions.h"
#include "ormpropertyinterface.h"
#include "ormpropertysizet.h"
#include "ormpropertyuuid.h"
#include "ormpropertystring.h"
#include "ormpropertydatetime.h"
#include "ormpropertybool.h"

#define MACRO_addProperty(name) \
    addProperty(#name, name)

class ORMObjectInterface
{
    typedef std::map<ORMString, ORMPropertyInterface*> PropertyMap;
    PropertyMap properties;
protected:
    void addProperty(ORMString propertyName, ORMPropertyInterface &property);
public:
    ORMObjectInterface();
    virtual ~ORMObjectInterface() {}
    virtual const ORMString getORMName() const = 0;
    virtual ORMObjectInterface *create() const = 0;

    bool propertyExists(const ORMString &propertyName) const;
    bool propertyIsNull(const ORMString &propertyName) const;
    void setPropertyNull(const ORMString &propertyName,
                         const bool n);

    ORMString getPropertyToString(const ORMString &propertyName) const;
    void setPropertyFromString(const ORMString &propertyName,
                               const ORMString &value);


    void getPropertyNames(std::set<ORMString> &propertyNames) const;
};

#endif // ORMOBJECTINTERFACE_H
