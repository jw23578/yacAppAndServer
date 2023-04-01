#ifndef ORMFACTORY_H
#define ORMFACTORY_H

#include "t0009_appuser_logintoken.h"
#include "t0026_appuser_tag.h"

class ORMFactory
{
    std::map<ORMString, ORMObjectInterface*> name2ghost;
    void addGhost(ORMObjectInterface *ghost);
public:
    ORMFactory();

    ORMObjectInterface *create(const ORMString &ORMName) const;
};

#endif // ORMFACTORY_H
