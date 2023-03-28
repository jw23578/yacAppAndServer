#include "ormobjectinterface.h"

void ORMObjectInterface::addProperty(ORMString propertyName, ORMPropertyInterface &property)
{
    properties[propertyName] = &property;
}

ORMObjectInterface::ORMObjectInterface()
{

}

ORMString ORMObjectInterface::getValueToString(const ORMString &propertyName) const
{
    const auto it(properties.find(propertyName));
    if (it == properties.end())
    {
        return "";
    }
    return it->second->asString();
}

void ORMObjectInterface::setValueFromString(const ORMString &propertyName,
                                            const ORMString &value)
{
    const auto it(properties.find(propertyName));
    if (it == properties.end())
    {
        return;
    }
    it->second->fromString(value);
}

void ORMObjectInterface::getPropertyNames(std::set<ORMString> &propertyNames)
{
    for (const auto &pn: properties)
    {
        propertyNames.insert(pn.first);
    }
}
