#include "yacormfactory.h"
#include "t0009_appuser_logintoken.h"
#include "t0021_right_group.h"
#include "t0022_right_group2appuser.h"
#include "t0023_right2rightgroup.h"
#include "t0026_appuser_tag.h"

YACORMFactory::YACORMFactory():ORMFactory<YACBaseObject>()
{
    addGhost(new t0009_appuser_logintoken);
    addGhost(new t0021_right_group);
    addGhost(new t0022_right_group2appuser);
    addGhost(new t0023_right2rightgroup);
    addGhost(new t0026_appuser_tag);
}
