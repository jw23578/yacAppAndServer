#include "ormpropertyuuid.h"

ORMPropertyUuid::ORMPropertyUuid():ORMTemplatedPropertyInterface<ORMUuid>()
{

}

ORMString ORMPropertyUuid::asString() const
{
#ifdef ORMCPPTypes
    return get().str();
#endif

#ifdef ORMQTTypes
    return get();
#endif
}

void ORMPropertyUuid::fromString(const ORMString &value)
{
#ifdef ORMCPPTypes
    set(sole::rebuild(value));
#endif

#ifdef ORMQTTypes
    set(value);
#endif

}
