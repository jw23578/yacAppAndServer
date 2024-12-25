#include "ormpropertyoid.h"

ORMPropertyOID::ORMPropertyOID(const ORMString &name):ORMTemplatedPropertyInterface<size_t>(name)
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

ORMString ORMPropertyOID::asJson() const
{
    return asString();
}

