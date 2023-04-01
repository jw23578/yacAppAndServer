#include "ormfactory.h"
#include "t0009_appuser_logintoken.h"
#include "t0026_appuser_tag.h"
#include "t0021_right_group.h"


void ORMFactory::addGhost(ORMObjectInterface *ghost)
{
    name2ghost[ghost->getORMName()] = ghost;
}

ORMFactory::ORMFactory()
{
    addGhost(new t0009_appuser_logintoken);
    addGhost(new t0021_right_group);
    addGhost(new t0026_appuser_tag);
}

ORMObjectInterface *ORMFactory::create(const ORMString &ORMName) const
{
    const auto it(name2ghost.find(ORMName));
    if (it == name2ghost.end())
    {
        return 0;
    }
    return it->second->create();
}
