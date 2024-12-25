#include "ormpropertyint.h"

ORMPropertyInt::ORMPropertyInt(const ORMString &name):ORMTemplatedPropertyInterface<int>(name)
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
    char* end(nullptr);
    set(std::strtoul(value.c_str(), &end, 10));
#endif

#ifdef ORMQTTypes
    set(value.toInt());
#endif

}

ORMString ORMPropertyInt::asJson() const
{
    return asString();
}
