#include "ormpropertyinterface.h"

ORMPropertyInterface::ORMPropertyInterface():bNull(true)
{
    details.insert(DetailDB);
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

void ORMPropertyInterface::clearDetails()
{
    details.clear();
}

void ORMPropertyInterface::addDetail(const ORMPropertyDetails detail)
{
    details.insert(detail);
}

bool ORMPropertyInterface::hasDetail(const ORMPropertyDetails needle)
{
    return details.find(needle) != details.end();
}
