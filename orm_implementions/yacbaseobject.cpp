#include "yacbaseobject.h"

bool YACBaseObject::shouldBeIndexed(const ORMString &propertyName) const
{
    return propertyNamesToHaveAnIndex.find(propertyName) != propertyNamesToHaveAnIndex.end();
}

bool YACBaseObject::isTransferProperty(const ORMString &propertyName) const
{
    return transferProperties.find(propertyName) != transferProperties.end();
}

void YACBaseObject::assign(const YACBaseObject &other)
{
    if (this == &other)
    {
        return;
    }
    for (const auto &pn: propertyNames())
    {
        setPropertyFromString(pn, other.getPropertyToString(pn));
    }
}
