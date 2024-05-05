#include "ormmap.h"

ORMMap::ORMMap() {}

ORMMap::~ORMMap()
{
    for (auto &e : id2object)
    {
        delete e.second;
    }
    id2object.clear();
}

ORMObjectInterfacePointer &ORMMap::operator[](const ORMUuid id)
{
    return id2object[id];
}

ORMObjectInterfacePointer ORMMap::find(const ORMUuid id)
{
    auto e(id2object.find(id));
    if (e == id2object.end())
    {
        return 0;
    }
    return e->second;
}

bool ORMMap::contains(const ORMUuid id)
{
    return find(id) != 0;
}

ORMObjectInterfacePointer ORMMap::find(const ORMString &propertyName,
                                       const ORMString &value)
{
    for (auto &e : id2object)
    {
        if (e.second->getString(propertyName) == value)
        {
            return e.second;
        }
    }
    return 0;
}
