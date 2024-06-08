#include "ormpropertyint.h"

ORMPropertyInt::ORMPropertyInt():ORMTemplatedPropertyInterface<int>()
{
}

ORMString ORMPropertyInt::asString() const
{
#ifdef ORMCPPTypes
    return std::to_string(get());
#endif

#ifdef ORMQTTypes
    return QString::number(get());
#endif
}

void ORMPropertyInt::fromString(const ORMString &value)
{
#ifdef ORMCPPTypes
    set(std::stoul(value));
#endif

#ifdef ORMQTTypes
    set(value.toInt());
#endif

}

ORMString ORMPropertyInt::asJson() const
{
    return asString();
}
