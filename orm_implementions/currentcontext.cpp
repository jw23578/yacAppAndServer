#include "currentcontext.h"

CurrentContext::CurrentContext(ORMPersistenceInterface &opi, const reducedsole::uuid &appId, const reducedsole::uuid &userId):
    opi(opi),
    appId(appId),
    userId(userId)
{

}
