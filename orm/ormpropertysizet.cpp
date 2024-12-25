#include "ormpropertysizet.h"

ORMPropertySizeT::ORMPropertySizeT(const ORMString &name):ORMTemplatedPropertyInterface<size_t>(name)
{

}

ORMString ORMPropertySizeT::asString() const
{
#ifdef ORMCPPTypes
    return std::to_string(get());
#endif

#ifdef ORMQTTypes
    return QString::number(get());
#endif
}

void ORMPropertySizeT::fromString(const ORMString &value)
{
#ifdef ORMCPPTypes
    set(std::stoul(value));
#endif

#ifdef ORMQTTypes
    set(value.toUInt());
#endif
}

ORMString ORMPropertySizeT::asJson() const
{
    return asString();
}
