#include "t0002_user.h"
#include "ormpersistenceinterface.h"
#include "t0003_user_passwordhashes.h"
#include "t0004_user_logintoken.h"

std::map<ORMString, ORMUuid> t0002_user::loginEMailAndAppId2AppUserId;


void t0002_user::clearUpdatePasswordToken()
{
    setupdate_password_token("");
    update_password_token_valid_untilORM().setNull(true);
}

bool t0002_user::loadByLoginEMail(CurrentContext &context,
                                  const ORMString &loginEMail)
{
    return load(context,
                {{loginemailORM().name(), loginEMail}});
}

bool t0002_user::lookupUser(CurrentContext &context,
                            const ORMString &loginEMail,
                            std::string &message)
{
    auto it(loginEMailAndAppId2AppUserId.find(loginEMail + ExtUuid::uuidToString(context.appId)));
    if (it != loginEMailAndAppId2AppUserId.end())
    {
        context.opi.selectObject(it->second,
                                 *this);
        return true;
    }
    if (!loadByLoginEMail(context,
                          loginEMail))
    {
        message = "LoginEMail/User not found. Please check your LoginEMail or register first.";
        return false;
    }
    if (verifiedORM().isNull())
    {
        message = "LoginEMail/User not yet verified";
        return false;
    }
    loginEMailAndAppId2AppUserId[loginEMail + ExtUuid::uuidToString(context.appId)] = getuser_id();
    return true;
}

bool t0002_user::registerUser(CurrentContext &context,
                              const ORMString &loginEMail,
                              const ORMString &password,
                              std::string &message)
{
    Log::Scope scope("createAppUser");
    if (loadByLoginEMail(context, loginEMail))
    {
        message = "LoginEMail already exists.";
        return false;
    }
    if (password.size() == 0)
    {
        message = "Password is empty.";
        return false;
    }
    setfstname("");
    setsurname("");
    setvisible_name("");
    verifiedORM().setNull(true);
    setloginemail(loginEMail);
    setverify_token(ExtString::randomString(0, 0, 4, 0));
    setverify_token_valid_until(MACRO_TIMEPOINT_TO_ORM(std::chrono::system_clock::now() + std::chrono::minutes(60)));
    setupdate_password_token("");
    update_password_token_valid_untilORM().setNull(true);
    deletedORM().setNull(true);
    setsearching_exactly_allowed(false); // FIXME
    setsearching_fuzzy_allowed(true); // FIXME
    setpublic_key_base64(""); // FIXME
    image_idORM().setNull(true); // FIXME
    store(context);

    if (password.size())
    {
        t0003_user_passwordhashes passwordHash;
        passwordHash.setuser_id(getuser_id());
        passwordHash.setpassword_hash(password);
        passwordHash.store(context);
    }

    return true;
}

bool t0002_user::verifyUser(CurrentContext &context,
                            const ORMString &loginEMail,
                            const ORMString &verifyToken,
                            ORMString &loginToken,
                            std::string &message)
{
    if (!loadByLoginEMail(context, loginEMail))
    {
        message = std::string("no appuser with loginEMail: ") + ExtString::quote(MACRO_ORM_STRING_2_STD_STRING(loginEMail)) + std::string(" found");
        return false;
    }
    LogStatController::slog(__FILE__, __LINE__, LogStatController::verbose,
                            std::string("verify_token_valid_until as string: ") + MACRO_ORM_STRING_2_STD_STRING(verify_token_valid_untilORM().asString()));

    LogStatController::slog(__FILE__, __LINE__, LogStatController::verbose,
                            std::string("verify_token_valid_until: ") + ExtString::timepointToISO(MACRO_ORM_TO_TIMEPOINT(getverify_token_valid_until())));

    std::chrono::system_clock::time_point now(std::chrono::system_clock::now());
    LogStatController::slog(__FILE__, __LINE__, LogStatController::verbose,
                            std::string("now: ") + ExtString::timepointToISO(now));
    if (MACRO_ORM_TO_TIMEPOINT(getverify_token_valid_until()) < now)
    {
        message = std::string("Token not valid any more, please request new Token.");
        return false;
    }
    if (getverify_token() != verifyToken)
    {
        message = std::string("wrong token");
        return false;
    }

    {
        setverified(MACRO_TIMEPOINT_TO_ORM(TimePointPostgreSqlNow));
        setverify_token("");
        verify_token_valid_untilORM().setNull(true);
        store(context);
    }
    t0004_user_logintoken userLogintoken;
    userLogintoken.loginSuccessful(context, getuser_id());
    loginToken = userLogintoken.getlogin_token();
    return true;
}

bool t0002_user::createVerifyToken(CurrentContext &context,
                                   const ORMString &loginEMail,
                                   std::string &message)
{
    if (!loadByLoginEMail(context,  loginEMail))
    {
        message = "LoginEMail does not exist.";
        return false;
    }
    setverify_token(ExtString::randomString(0, 0, 4, 0));
    setverify_token_valid_until(MACRO_TIMEPOINT_TO_ORM(std::chrono::system_clock::now() + std::chrono::minutes(60)));
    store(context);
    return true;
}

bool t0002_user::createVerifiedAppUser(CurrentContext &context,
                                       const ORMString &loginEMail,
                                       const ORMString &fstname,
                                       const ORMString &surname,
                                       const ORMString &visible_name,
                                       const bool searching_exactly_allowed,
                                       const bool searching_fuzzy_allowed,
                                       const ORMString &public_key_base64,
                                       std::string &message)
{
    if (loadByLoginEMail(context, loginEMail))
    {
        message = "LoginEMail already exists.";
        return false;
    }
    this->setfstname(fstname);
    this->setsurname(surname);
    this->setvisible_name(visible_name);
    setverified(MACRO_TIMEPOINT_TO_ORM(std::chrono::system_clock::now()));
    setloginemail(loginEMail);
    setverify_token("");
    verify_token_valid_untilORM().setNull(true);
    setupdate_password_token("");
    update_password_token_valid_untilORM().setNull(true);
    deletedORM().setNull(true);
    this->setsearching_exactly_allowed(searching_exactly_allowed);
    this->setsearching_fuzzy_allowed(searching_fuzzy_allowed);
    this->setpublic_key_base64(public_key_base64);
    image_idORM().setNull(true);
    store(context);
    return true;
}

bool t0002_user::updatePassword(CurrentContext &context,
                                const ORMString &loginEMail,
                                const ORMString &updatePasswordToken,
                                const ORMString &password,
                                std::string &message,
                                ORMString &loginToken)
{
    if (!loadByLoginEMail(context, loginEMail))
    {
        message = std::string("no user with loginEMail: ") + ExtString::quote(MACRO_ORM_STRING_2_STD_STRING(loginEMail)) + std::string(" found");
        return false;
    }
    if (update_password_token_valid_untilORM().isNull())
    {
        message = std::string("no update password token requested");
        return false;
    }
    std::chrono::system_clock::time_point now(std::chrono::system_clock::now());
    if (MACRO_ORM_TO_TIMEPOINT(getupdate_password_token_valid_until()) < now)
    {
        message = std::string("update password token not valid any more, please request update password again.");
        clearUpdatePasswordToken();
        store(context);
        return false;
    }
    if (getupdate_password_token() != updatePasswordToken)
    {
        message = std::string("wrong updatePasswordToken");
        return false;
    }
    clearUpdatePasswordToken();
    store(context);

    t0003_user_passwordhashes passwordhash;
    passwordhash.load(context, {{t0003_user_passwordhashes().user_idORM().name(), user_idORM().asString()}});
    passwordhash.setuser_id(getuser_id());
    passwordhash.setpassword_hash(password);
    passwordhash.store(context);

    t0004_user_logintoken ::disableLoginTokenByUserId(context, getuser_id());

    t0004_user_logintoken userLogintoken;
    userLogintoken.loginSuccessful(context, getuser_id());
    loginToken = userLogintoken.getlogin_token();
    message = "update password successful";
    return true;

}

bool t0002_user::requestUpdatePassword(CurrentContext &context,
                                       const ORMString &loginEMail,
                                       std::string &message)
{
    if (!lookupUser(context, loginEMail, message))
    {
        return false;
    }
    setupdate_password_token(ExtString::randomString(0, 0, 4, 0));
    setupdate_password_token_valid_until(MACRO_TIMEPOINT_TO_ORM(std::chrono::system_clock::now() + std::chrono::minutes(60)));
    store(context);
    return true;
}
