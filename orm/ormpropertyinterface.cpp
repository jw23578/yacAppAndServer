#include "ormpropertyinterface.h"

ORMPropertyInterface::ORMPropertyInterface(const ORMString &name):bNull(true), m_name(name)
{
    details.insert(DetailDB);
}

const ORMString &ORMPropertyInterface::name() const
{
    return m_name;
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
