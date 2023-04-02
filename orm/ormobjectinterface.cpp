#include "ormobjectinterface.h"

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

bool ORMObjectInterface::proptertyIsBool(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyBool*>(it->second) != 0;
}

bool ORMObjectInterface::proptertyIsUuid(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyUuid*>(it->second) != 0;
}

bool ORMObjectInterface::proptertyIsInt(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyInt*>(it->second) != 0;
}

bool ORMObjectInterface::proptertyIsSizeT(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertySizeT*>(it->second) != 0;
}

bool ORMObjectInterface::proptertyIsDateTime(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyDateTime*>(it->second) != 0;
}

bool ORMObjectInterface::proptertyIsString(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, false);
    return dynamic_cast<ORMPropertyString*>(it->second) != 0;
}

ORMString ORMObjectInterface::getPropertyToString(const ORMString &propertyName) const
{
    MACRO_ConstPropertyIterator(propertyName, "");
    return it->second->asString();
}

void ORMObjectInterface::setPropertyFromString(const ORMString &propertyName,
                                            const ORMString &value)
{
    MACRO_ConstPropertyIterator(propertyName, );
    it->second->fromString(value);
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
