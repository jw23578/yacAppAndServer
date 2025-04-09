#ifndef YACORMFACTORY_H
#define YACORMFACTORY_H

#include "yacbaseobject.h"
#include "ormfactory.h"

class YACORMFactory: public ORMFactory<YACBaseObject>
{
public:
    YACORMFactory();
};

#endif // YACORMFACTORY_H
