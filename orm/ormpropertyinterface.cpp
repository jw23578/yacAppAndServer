#include "ormpropertyinterface.h"

ORMPropertyInterface::ORMPropertyInterface():bNull(true)
{

}

void ORMPropertyInterface::setNull(const bool n)
{
    bNull = n;
}

bool ORMPropertyInterface::isNull() const
{
    return bNull;
}
