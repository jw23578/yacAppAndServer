#include "t0002_user.h"
#include "ormpersistenceinterface.h"
#include "t0003_user_passwordhashes.h"
#include "t0004_user_logintoken.h"

std::map<std::string, reducedsole::uuid> t0002_user::loginEMailAndAppId2AppUserId;


void t0002_user::clearUpdatePasswordToken()
{
    update_password_token = "";
    update_password_token_valid_until.setNull(true);
}

bool t0002_user::loadByLoginEMail(CurrentContext &context,
                                  const ORMString &loginEMail)
{
    return load(context,
                {{loginemail.name(), loginEMail}});
}

bool t0002_user::lookupUser(CurrentContext &context,
                            const std::string &loginEMail,
                            t0002_user &resultUser,
                            std::string &message)
{
    auto it(loginEMailAndAppId2AppUserId.find(loginEMail + context.appId.str()));
    if (it != loginEMailAndAppId2AppUserId.end())
    {
        context.opi.selectObject(it->second,
                                 resultUser);
        return true;
    }
    if (!resultUser.loadByLoginEMail(context,
                                     loginEMail))
    {
        message = "LoginEMail/User not found. Please check your LoginEMail or register first.";
        return false;
    }
    if (resultUser.verified.isNull())
    {
        message = "LoginEMail/User not yet verified";
        return false;
    }
    loginEMailAndAppId2AppUserId[loginEMail + context.appId.str()] = resultUser.user_id;
    return true;
}

bool t0002_user::registerUser(CurrentContext &context,
                              const std::string &loginEMail,
                              const std::string &password,
                              std::string &message)
{
    Log::Scope scope("createAppUser");
    if (loadByLoginEMail(context, loginEMail))
    {
        message = "LoginEMail already exists.";
        return false;
    }
    fstname = "";
    surname = "";
    visible_name = "";
    verified.setNull(true);
    loginemail = loginEMail;
    verify_token = ExtString::randomString(0, 0, 4, 0);
    verify_token_valid_until = std::chrono::system_clock::now() + std::chrono::minutes(60);
    update_password_token =  "";
    update_password_token_valid_until.setNull(true);
    deleted.setNull(true);
    searching_exactly_allowed = false; // FIXME
    searching_fuzzy_allowed = true; // FIXME
    public_key_base64 = ""; // FIXME
    image_id.setNull(true); // FIXME
    store(context);

    if (password.size())
    {
        t0003_user_passwordhashes passwordHash;
        passwordHash.user_id = user_id;
        passwordHash.password_hash = password;
        passwordHash.store(context);
    }

    return true;
}

bool t0002_user::verifyUser(CurrentContext &context,
                            const std::string &loginEMail,
                            const std::string &verifyToken,
                            std::string &loginToken,
                            std::string &message)
{
    if (!loadByLoginEMail(context, loginEMail))
    {
        message = std::string("no appuser with loginEMail: ") + ExtString::quote(loginEMail) + std::string(" found");
        return false;
    }
    LogStatController::slog(__FILE__, __LINE__, LogStatController::verbose,
                            std::string("verify_token_valid_until as string: ") + verify_token_valid_until.asString());

    LogStatController::slog(__FILE__, __LINE__, LogStatController::verbose,
                            std::string("verify_token_valid_until: ") + ExtString::timepointToISO(verify_token_valid_until));

    std::chrono::system_clock::time_point now(std::chrono::system_clock::now());
    LogStatController::slog(__FILE__, __LINE__, LogStatController::verbose,
                            std::string("now: ") + ExtString::timepointToISO(now));
    if (verify_token_valid_until < now)
    {
        message = std::string("Token not valid any more, please request new Token.");
        return false;
    }
    if (verify_token != verifyToken)
    {
        message = std::string("wrong token");
        return false;
    }

    {
        verified = TimePointPostgreSqlNow;
        verify_token = "";
        verify_token_valid_until.setNull(true);
        store(context);
    }
    t0004_user_logintoken userLogintoken;
    userLogintoken.loginSuccessful(context, user_id);
    loginToken = userLogintoken.login_token;
    return true;
}

bool t0002_user::createVerifyToken(CurrentContext &context,
                                   const std::string &loginEMail,
                                   std::string &message)
{
    if (!loadByLoginEMail(context,  loginEMail))
    {
        message = "LoginEMail does not exist.";
        return false;
    }
    verify_token = ExtString::randomString(0, 0, 4, 0);
    verify_token_valid_until = std::chrono::system_clock::now() + std::chrono::minutes(60);
    store(context);
    return true;
}

bool t0002_user::createVerifiedAppUser(CurrentContext &context,
                                       const std::string &loginEMail,
                                       const std::string &fstname,
                                       const std::string &surname,
                                       const std::string &visible_name,
                                       const bool searching_exactly_allowed,
                                       const bool searching_fuzzy_allowed,
                                       const std::string &public_key_base64,
                                       std::string &message)
{
    if (loadByLoginEMail(context, loginEMail))
    {
        message = "LoginEMail already exists.";
        return false;
    }
    this->fstname = fstname;
    this->surname = surname;
    this->visible_name = visible_name;
    verified = std::chrono::system_clock::now();
    loginemail = loginEMail;
    verify_token = "";
    verify_token_valid_until.setNull(true);
    update_password_token = "";
    update_password_token_valid_until.setNull(true);
    deleted.setNull(true);
    this->searching_exactly_allowed = searching_exactly_allowed;
    this->searching_fuzzy_allowed = searching_fuzzy_allowed;
    this->public_key_base64 = public_key_base64;
    image_id.setNull(true);
    store(context);
    return true;
}
