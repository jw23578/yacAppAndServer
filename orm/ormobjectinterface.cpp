#include "ormobjectinterface.h"
#include "utils/extstring.h"

#define MACRO_ConstPropertyIterator(propertyName, returnValue) \
    const auto it(properties.find(propertyName)); \
    if (it == properties.end()) \
    { \
        return returnValue; \
    }

std::map<ORMString, std::set<ORMString>> ORMObjectInterface::allPropertySets;

void ORMObjectInterface::addProperty(ORMString propertyName, ORMPropertyInterface &property)
{
    properties[propertyName] = &property;
}

ORMPropertyInterface *ORMObjectInterface::getProperty(const ORMString &propertyName) const
{
    if (!propertyExists(propertyName))
    {
        return 0;
    }
    return properties.at(propertyName);
}

bool ORMObjectInterface::propertyExists(const ORMString &propertyName) const
{
    return properties.find(propertyName) != properties.end();
}

bool ORMObjectInterface::propertyIsNull(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, true);
    return it->second->isNull();
}

void ORMObjectInterface::setPropertyNull(const ORMString &propertyName,
                                         const bool n)
{
    MACRO_ConstPropertyIterator(propertyName, );
    it->second->setNull(n);
}

bool ORMObjectInterface::propertyIsBool(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyBool*>(it->second) != 0;
}

bool ORMObjectInterface::propertyIsUuid(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyUuid*>(it->second) != 0;
}

bool ORMObjectInterface::propertyIsInt(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyInt*>(it->second) != 0;
}

bool ORMObjectInterface::propertyIsSizeT(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertySizeT*>(it->second) != 0;
}

bool ORMObjectInterface::propertyIsDateTime(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyDateTime*>(it->second) != 0;
}

bool ORMObjectInterface::propertyIsString(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyString*>(it->second) != 0;
}

ORMString ORMObjectInterface::getString(const ORMString &propertyName) const
{
    if (!propertyIsString(propertyName))
    {
        return "";
    }
    return properties.at(propertyName)->asString();
}

bool ORMObjectInterface::propertyIsOid(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyOID*>(it->second) != 0;
}

ORMString ORMObjectInterface::getPropertyToString(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, "");
    return it->second->asString();
}

bool ORMObjectInterface::setPropertyFromString(const ORMString &propertyName,
                                               const ORMString &value)
{
    MACRO_ConstPropertyIterator(propertyName, false);
    it->second->fromString(value);
    return true;
}

bool ORMObjectInterface::setUuid(const ORMString &propertyName,
                                 const ORMUuid &uuid)
{
    MACRO_ConstPropertyIterator(propertyName, false);
    ORMPropertyUuid *uuidProperty(dynamic_cast<ORMPropertyUuid*>(it->second));
    if (!uuidProperty)
    {
        return false;
    }
    uuidProperty->set(uuid);
    return true;
}

const std::set<ORMString> &ORMObjectInterface::propertyNames() const
{
    const auto it(allPropertySets.find(getORMName()));
    if (it != allPropertySets.end())
    {
        return it->second;
    }
    for (const auto &pn: properties)
    {
        allPropertySets[getORMName()].insert(pn.first);
    }
    return allPropertySets[getORMName()];
}

ORMString ORMObjectInterface::toString() const
{
    ORMString result;
    bool first(true);
    for (auto &p: properties)
    {
        if (!first)
        {
            result += ",";
        }
        first = false;
        result += ExtString::quote(MACRO_ORM_STRING_2_STD_STRING(p.first));
        result += ":";
        result += p.second->asJson();
    }
    return result;
}

void ORMObjectInterface::fill(ORMSqlInterface &sqlInterface)
{
    const std::set<ORMString> &pn(propertyNames());
    for (auto &n: pn)
    {
        ORMPropertyInterface *pi(getProperty(n));
        if (pi->hasDetail(DetailDB))
        {
            pi->fromString(MACRO_STD_STRING_2_ORM_STRING(sqlInterface.value(MACRO_ORM_STRING_2_STD_STRING(n)).value_or("")));
        }
    }
}
