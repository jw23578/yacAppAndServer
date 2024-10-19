#include "extuuid.h"

ExtUuid::ExtUuid() {}

#ifdef ORMQTTypes
const ORMUuid ExtUuid::NullUuid;

ORMUuid ExtUuid::generateUuid()
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}

ORMString ExtUuid::uuidToString(ORMUuid const &id)
{
    return id;
}
ORMUuid ExtUuid::stringToUuid(ORMString const &str)
{
    return str;
}

#endif

#ifdef ORMCPPTypes
const ORMUuid ExtUuid::NullUuid = sole::rebuild("00000000-0000-0000-0000-000000000000");

ORMUuid ExtUuid::generateUuid()
{
    return sole::uuid4();
}

ORMString ExtUuid::uuidToString(ORMUuid const &id)
{
    return id.str();
}

ORMUuid ExtUuid::stringToUuid(ORMString const &str)
{
    return sole::rebuild(str);
}


#define Q_OBJECT
#endif
