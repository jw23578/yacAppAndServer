#ifndef ORMSQLINTERFACE_H
#define ORMSQLINTERFACE_H

#include "orm_implementions/sqlstring.h"
#include <optional>

class ORMSqlInterface
{
    std::map<std::string, size_t> columnName2Index;
    void fillColumnNames();
protected:
    size_t currentRow = {0};
public:
    ORMSqlInterface();
    virtual ~ORMSqlInterface() {}

    virtual bool execute(SqlString const &sql) = 0;
    virtual bool open(SqlString const &sql) = 0;
    virtual size_t size() = 0;
    virtual bool next() = 0;
    virtual void goToRow(size_t r) = 0;
    size_t getCurrentRow();
    virtual size_t storeBlob(std::vector<char> const &data) = 0;
    virtual bool fetchBlob(size_t blobId, std::vector<char> &data) = 0;

    virtual size_t columns() = 0;
    virtual std::string columnName(size_t index) = 0;

    virtual std::optional<std::string> value(size_t index) = 0;
    virtual std::optional<int> intValue(size_t index) = 0;
    virtual std::optional<std::chrono::system_clock::time_point> timepointValue(size_t index) = 0;

    virtual std::optional<std::string> value(std::string const &columnName);
    virtual std::optional<int> intValue(std::string const &columnName);
    virtual std::optional<std::chrono::system_clock::time_point> timepointValue(std::string const &columnName);
};

#endif // ORMSQLINTERFACE_H
