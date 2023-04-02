#include "yacbaseobject.h"

bool YACBaseObject::shouldBeIndexed(const ORMString &propertyName) const
{
    return propertyNamesToHaveAnIndex.find(propertyName) != propertyNamesToHaveAnIndex.end();
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
