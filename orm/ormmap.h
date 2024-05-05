#ifndef ORMMAP_H
#define ORMMAP_H

#include <map>
#include "ormobjectinterface.h"

class ORMMap
{
    std::map<ORMUuid, ORMObjectInterfacePointer> id2object;
public:
    ORMMap();
    ~ORMMap();

    ORMObjectInterfacePointer &operator[](const ORMUuid id);
    ORMObjectInterfacePointer find(const ORMUuid id);
    bool contains(const ORMUuid id);

    ORMObjectInterfacePointer find(const ORMString &propertyName,
                                   const ORMString &value);

};

#endif // ORMMAP_H
