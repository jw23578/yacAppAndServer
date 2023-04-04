#include "ormpropertyoid.h"

ORMPropertyOID::ORMPropertyOID():ORMTemplatedPropertyInterface<size_t>()
{

}

ORMString ORMPropertyOID::asString() const
{
#ifdef ORMCPPTypes
    return std::to_string(get());
#endif

#ifdef ORMQTTypes
    return QString::number(get());
#endif
}

void ORMPropertyOID::fromString(const ORMString &value)
{
#ifdef ORMCPPTypes
    set(std::stoul(value));
#endif

#ifdef ORMQTTypes
    set(value.toUInt());
#endif
}

