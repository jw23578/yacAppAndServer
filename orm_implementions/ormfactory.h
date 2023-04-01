#ifndef ORMFACTORY_H
#define ORMFACTORY_H

#include "orm/ormobjectinterface.h"

class ORMFactory
{
    std::set<ORMString> ormNames;
    std::map<ORMString, ORMObjectInterface*> name2ghost;
    void addGhost(ORMObjectInterface *ghost);
public:
    ORMFactory();

    const std::set<ORMString> &getORMNames() const;

    ORMObjectInterface *create(const ORMString &ORMName) const;
};

#endif // ORMFACTORY_H
