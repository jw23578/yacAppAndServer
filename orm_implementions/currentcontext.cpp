#include "currentcontext.h"


const ORMString CurrentContext::superUserFstname = "superUser";
const ORMString CurrentContext::superUserSurname = "superUser";

CurrentContext::CurrentContext(ORMPersistenceInterface &opi,
                               const ORMUuid &appId,
                               const ORMUuid &userId):
    opi(opi),
    appId(appId),
    userId(userId)
{

}
