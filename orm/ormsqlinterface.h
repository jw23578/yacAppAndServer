#ifndef ORMSQLINTERFACE_H
#define ORMSQLINTERFACE_H

#include "sqlstring.h"
#include <optional>
class ORMPersistenceInterface;
class ORMObjectInterface;

class ORMSqlInterface
{
    friend ORMPersistenceInterface;
    friend ORMObjectInterface;
    std::map<std::string, size_t> columnName2Index;
    void fillColumnNames();
protected:
    size_t currentRow = {0};
    virtual bool internalExecute(SqlString const &sql) = 0;
    virtual bool internalOpen(SqlString const &sql) = 0;

    bool execute(SqlString const &sql);
    bool open(SqlString const &sql);

    virtual size_t size() = 0;
    virtual bool next() = 0;
    void goToRow(size_t r);
    size_t getCurrentRow();
    virtual size_t storeBlob(std::basic_string<std::byte> const &data) = 0;
    virtual bool fetchBlob(size_t blobId, std::basic_string<std::byte> &data) = 0;

    virtual size_t columns() = 0;
    virtual std::string columnName(size_t index) = 0;
    bool columnExists(const std::string columnName);

    virtual bool isNull(size_t index) = 0;
    virtual std::optional<std::string> value(size_t index) = 0;
    virtual std::optional<ORMUuid> uuidValue(size_t index) = 0;
    virtual std::optional<int> intValue(size_t index) = 0;
    virtual std::optional<std::chrono::system_clock::time_point> timepointValue(size_t index) = 0;

    bool isNull(std::string const &columnName);
    std::optional<std::string> value(std::string const &columnName);
    std::optional<ORMUuid> uuidValue(std::string const &columnName);
    std::optional<int> intValue(std::string const &columnName);
    std::optional<std::chrono::system_clock::time_point> timepointValue(std::string const &columnName);

public:
    ORMSqlInterface();
    virtual ~ORMSqlInterface() {}

};

#endif // ORMSQLINTERFACE_H
