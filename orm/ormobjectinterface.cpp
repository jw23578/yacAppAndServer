#include "ormobjectinterface.h"

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
    const auto it(properties.find(propertyName));
    if (it == properties.end())
    {
        return true;
    }
    return it->second->isNull();
}

void ORMObjectInterface::setPropertyNull(const ORMString &propertyName,
                                         const bool n)
{
    const auto it(properties.find(propertyName));
    if (it == properties.end())
    {
        return;
    }
    it->second->setNull(n);
}

ORMString ORMObjectInterface::getPropertyToString(const ORMString &propertyName) const
{
    const auto it(properties.find(propertyName));
    if (it == properties.end())
    {
        return "";
    }
    return it->second->asString();
}

void ORMObjectInterface::setPropertyFromString(const ORMString &propertyName,
                                            const ORMString &value)
{
    const auto it(properties.find(propertyName));
    if (it == properties.end())
    {
        return;
    }
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
