#include "ormpropertyuuid.h"

ORMPropertyUuid::ORMPropertyUuid():ORMTemplatedPropertyInterface<ORMUuid>()
{
#ifdef ORMCPPTypes
    sole::uuid u;
    u.ab = 0;
    u.cd = 0;
    set(u);
#endif

#ifdef ORMQTTypes
    // is correct initialized
#endif
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
