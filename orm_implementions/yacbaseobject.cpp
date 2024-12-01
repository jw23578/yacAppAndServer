#include "yacbaseobject.h"

void YACBaseObject::generateID()
{
    setid(ExtUuid::generateUuid());
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
