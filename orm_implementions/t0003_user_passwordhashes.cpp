#include "t0003_user_passwordhashes.h"

bool t0003_user_passwordhashes::login(CurrentContext &context,
                                      const ORMUuid &userId,
                                      const ORMString &password,
                                      std::string &message)
{
    SqlString sql("select *, ");
    sql += password_hashORM().name();
    sql += " = crypt(:password, ";
    sql += password_hashORM().name();
    sql += ") as login_ok from ";
    sql += getORMName();
    sql.addCompare("where", user_idORM().name(), "=", userId);
    context.opi.addOnlyInsertDBWhere(false, sql);
    sql.set("password", password);
    std::set<bool> loginOks;
    context.opi.fetchValues(sql, "login_ok", loginOks);
    if (!loginOks.size())
    {
        message = "Password is not set.";
        return false;
    }
    if (loginOks.size() > 1)
    {
        message = "More than one matching login/password, that is definitely not correct";
        return false;
    }
    bool result(*loginOks.begin() == true);
    if (!result)
    {
        message = "Password is wrong.";
    }
    return result;
}


