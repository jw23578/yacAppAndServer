#include "ormsqlinterface.h"

void ORMSqlInterface::fillColumnNames()
{
    if (columnName2Index.size())
    {
        return;
    }
    for (size_t i(0); i < columns(); ++i)
    {
        columnName2Index[columnName(i)] = i;
    }
}

ORMSqlInterface::ORMSqlInterface() {}

bool ORMSqlInterface::execute(const SqlString &sql)
{
    columnName2Index.clear();
    return internalExecute(sql);
}

bool ORMSqlInterface::open(const SqlString &sql)
{
    columnName2Index.clear();
    return internalOpen(sql);
}

void ORMSqlInterface::goToRow(size_t r)
{
    currentRow = r;
}

size_t ORMSqlInterface::getCurrentRow()
{
    return currentRow;
}

bool ORMSqlInterface::isNull(const std::string &columnName)
{
    fillColumnNames();
    return isNull(columnName2Index[columnName]);
}

std::optional<std::string> ORMSqlInterface::value(const std::string &columnName)
{
    fillColumnNames();
    return value(columnName2Index[columnName]);
}

std::optional<int> ORMSqlInterface::intValue(const std::string &columnName)
{
    fillColumnNames();
    return intValue(columnName2Index[columnName]);

}

std::optional<std::chrono::system_clock::time_point> ORMSqlInterface::timepointValue(const std::string &columnName)
{
    fillColumnNames();
    return timepointValue(columnName2Index[columnName]);
}
