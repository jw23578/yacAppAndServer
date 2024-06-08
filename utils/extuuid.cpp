#include "extuuid.h"

ExtUuid::ExtUuid() {}

#ifdef ORMQTTypes
ORMUuid ExtUuid::generateUuid()
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}

ORMString ExtUuid::uuidToString(ORMUuid const &id)
{
    return id;
}
#endif

#ifdef ORMCPPTypes
ORMUuid ExtUuid::generateUuid()
{
    return sole::uuid4();
}

ORMString ExtUuid::uuidToString(ORMUuid const &id)
{
    return id.str();
}
#define Q_OBJECT
#endif
