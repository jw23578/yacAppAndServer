#ifndef SQLSTRING_H
#define SQLSTRING_H

#include <string>
#include <chrono>
#include <iconv.h>
#include <vector>
#include <map>
#include "utils/reducedsole.h"
#include "utils/extstring.h" // marked as unused but is needed for MACRO_set
#include "utils/definitions.h"
#include "utils/extuuid.h"


#define MACRO_set(sql, fieldValue) \
sql.set(ExtString::lower(#fieldValue), fieldValue);

#define MACRO_setId() \
sql.set("id", sole::uuid4());

#define MACRO_addInsert(sql, fieldValue) \
sql.addInsert(#fieldValue, fieldValue, false);

#define MACRO_addSet(sql, fieldValue) \
sql.addSet(#fieldValue, fieldValue, false);

#define MACRO_addInsertOrSet(sql, fieldValue) \
sql.addInsertOrSet(#fieldValue, fieldValue, false);


class SqlString
{
    std::string sql;
    std::string insert2ndPart;
    std::string conflictAction;
    bool firstSetField{true};
    bool selectStatement{false};
    bool insertStatement{false};
    bool updateStatement{false};
    bool deleteStatement{false};
    void rawReplace(std::string &sql,
                    std::string const &param,
                    std::string value) const;
    std::string replaceVariables() const;
    std::string esc(std::string const &s);
    std::string quote(std::string const &s);
    std::map<std::string, std::string> variable2Values;
public:
    SqlString();
    SqlString(std::string const &s);
    void select(const std::string &field, const std::string &tableName);
    void select(std::string const &tableName);
    void update(std::string const &tableName);
    void insert(std::string const &tableName);
    void delet(std::string const &tableName);
    void insertOrUpdate(ORMUuid &id, std::string const &tableName);

    bool isUpdateStatement() const;

    void addOnConflict(const std::string &target, SqlString &onConflict);

    void set(std::string const &param,
             std::string const &value);
    void set(std::string const &param,
             const ORMUuid &value);
    void set(std::string const &param,
             const char * const value);
    void set(std::string const &param,
             uint64_t value);
    void set(std::string const &param,
             int value);
    void set(std::string const &param,
             unsigned int value);
    void set(std::string const &param,
             double value);
    void set(std::string const &param,
             bool value);
    void set(std::string const &param,
             std::chrono::system_clock::time_point const &tp);
    void set(std::string const &param,
             std::vector<uint64_t> const &v);

    template<class T>
    void set(std::string const &param,
             std::set<T> const &v)
    {
        if (v.size() == 0)
        {
            variable2Values[param] = "null";
            return;
        }
        auto it(v.begin());
        std::stringstream value;
        value << *it;
        ++it;
        while (it != v.end())
        {
            value << ", ";
            value << *it;
            ++it;
        }
        variable2Values[param] = value.str();
    }
    void set(const std::string &param,
             const std::set<reducedsole::uuid> &uuids);
    SqlString &operator=(std::string const &s);
    SqlString &operator+=(std::string const &s);
    SqlString &operator+=(SqlString const &s);
    char &operator[](size_t i);
    std::string str() const;
    size_t size() const;

    void replace(const std::string &needle,
                 const std::string &value);

    template <class T>
    void addCompare(const std::string &connector,
                    const std::string &needle,
                    const std::string &comparator,
                    const T &value)
    {
        sql += " " + connector;
        sql += " " + needle;
        sql += " " + comparator;
        std::string uuid(MACRO_ORM_STRING_2_STD_STRING(ExtUuid::uuidToString(ExtUuid::generateUuid())));
        sql += " :" + uuid;
        set(uuid, value);
    }

    template <class T>
    void addSet(const std::string &field,
                const T &value,
                const bool isNull)
    {
        if (isNull)
        {
            sql += firstSetField ? "" : ", ";
            sql += field + " = null ";
            firstSetField = false;
            return;
        }
        addCompare(firstSetField ? "" : ", ",
                   field,
                   "=",
                   value);
        firstSetField = false;
    }

    template <class T>
    void addInsert(const std::string &field,
                   const T &value,
                   const bool isNull)
    {
        if (isNull)
        {
            if (!firstSetField)
            {
                sql += ", ";
                insert2ndPart += ", ";
            }
            firstSetField = false;
            sql += field;
            insert2ndPart += "null";
            return;
        }
        if (!firstSetField)
        {
            sql += ", ";
            insert2ndPart += ", ";
        }
        firstSetField = false;
        sql += field;
        insert2ndPart += ":" + field;
        set(field, value);
    }

    template <class T>
    void addInsertOrSet(const std::string &field, const T &value, const bool isNull)
    {
        if (insertStatement)
        {
            addInsert(field, value, isNull);
        }
        if (updateStatement)
        {
            addSet(field, value, isNull);
        }
    }

    template <class T>
    void addInsertOrWhere(const std::string &connector,
                          const std::string &needleField,
                          const std::string &comparator,
                          const T &value)
    {
        if (insertStatement)
        {
            addInsert(needleField, value, false);
        }
        if (updateStatement)
        {
            addCompare(connector, needleField, comparator, value);
        }
    }

    void limit(const size_t limit, const size_t offset);
};

#endif // SQLSTRING_H
