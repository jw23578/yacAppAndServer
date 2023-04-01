#include "yacbaseobject.h"

void YACBaseObject::assign(const YACBaseObject &other)
{
    std::set<ORMString> propertyNames;
    getPropertyNames(propertyNames);
    for (const auto &pn: propertyNames)
    {
        setPropertyFromString(pn, other.getPropertyToString(pn));
    }
}
