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

void ORMPropertyInterface::callChangeCallback()
{
    if (!changeCallback)
    {
        return;
    }
    changeCallback();
}

void ORMPropertyInterface::setChangeCallback(std::function<void ()> cb)
{
    changeCallback = cb;
}
