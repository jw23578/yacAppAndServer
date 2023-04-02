#ifndef ORMFACTORY_H
#define ORMFACTORY_H

#include "ormobjectinterface.h"

template <class T>
class ORMFactory
{
    std::set<ORMString> ormNames;
    std::map<ORMString, T*> name2ghost;
protected:
    void addGhost(T *ghost)
    {
        ormNames.insert(ghost->getORMName());
        name2ghost[ghost->getORMName()] = ghost;
    }

public:
    ORMFactory(){}

    const std::set<ORMString> &getORMNames() const
    {
        return ormNames;
    }

    T *create(const ORMString &ORMName) const
    {
        const auto it(name2ghost.find(ORMName));
        if (it == name2ghost.end())
        {
            return 0;
        }
        return static_cast<T*>(it->second->create());
    }
};

#endif // ORMFACTORY_H
