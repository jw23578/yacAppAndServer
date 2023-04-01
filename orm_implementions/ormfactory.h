#ifndef ORMFACTORY_H
#define ORMFACTORY_H

#include "orm/ormobjectinterface.h"

class ORMFactory
{
    std::map<ORMString, ORMObjectInterface*> name2ghost;
    void addGhost(ORMObjectInterface *ghost);
public:
    ORMFactory();

    ORMObjectInterface *create(const ORMString &ORMName) const;
};

#endif // ORMFACTORY_H
