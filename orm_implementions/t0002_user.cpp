#include "t0002_user.h"
#include "ormpersistenceinterface.h"

void t0002_user::clearUpdatePasswordToken()
{
    update_password_token = "";
    update_password_token_valid_until.setNull(true);
}

bool t0002_user::loadByLoginEMail(ORMPersistenceInterface &opi,
                                  const reducedsole::uuid &appId,
                                  const ORMString &loginEMail)
{
    return opi.selectObject({{loginemail.name(), loginEMail},
                             {app_id.name(), appId.str()}}, *this);
}
