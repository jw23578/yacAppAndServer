#include "yacbaseobject.h"

void YACBaseObject::prepareFirstInsert()
{
    setUuid(getIDProperty()->name(), ExtUuid::generateUuid());
}

void YACBaseObject::assign(const YACBaseObject &other)
{
    if (this == &other)
    {
        return;
    }
    for (const auto &p: getProperties())
    {
        setPropertyFromString(p->name(), other.getPropertyToString(p->name()));
    }
}
