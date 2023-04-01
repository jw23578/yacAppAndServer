#ifndef ORMFACTORY_H
#define ORMFACTORY_H

#include "yacbaseobject.h"

class ORMFactory
{
    std::set<ORMString> ormNames;
    std::map<ORMString, YACBaseObject*> name2ghost;
    void addGhost(YACBaseObject *ghost);
public:
    ORMFactory();

    const std::set<ORMString> &getORMNames() const;

    YACBaseObject *create(const ORMString &ORMName) const;
};

#endif // ORMFACTORY_H
