#include "ormfactory.h"
#include "t0009_appuser_logintoken.h"
#include "t0021_right_group.h"
#include "t0022_right_group2appuser.h"
#include "t0023_right2rightgroup.h"
#include "t0026_appuser_tag.h"


void ORMFactory::addGhost(YACBaseObject *ghost)
{
    ormNames.insert(ghost->getORMName());
    name2ghost[ghost->getORMName()] = ghost;
}

ORMFactory::ORMFactory()
{
    addGhost(new t0009_appuser_logintoken);
    addGhost(new t0021_right_group);
    addGhost(new t0022_right_group2appuser);
    addGhost(new t0023_right2rightgroup);
    addGhost(new t0026_appuser_tag);
}

const std::set<ORMString> &ORMFactory::getORMNames() const
{
    return ormNames;
}

YACBaseObject *ORMFactory::create(const ORMString &ORMName) const
{
    const auto it(name2ghost.find(ORMName));
    if (it == name2ghost.end())
    {
        return 0;
    }
    return static_cast<YACBaseObject*>(it->second->create());
}
