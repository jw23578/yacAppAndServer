#ifndef ORMDEFINITIONS_H
#define ORMDEFINITIONS_H

#ifdef ORMQTTypes
#include <QString>
#include <QDateTime>
typedef QString ORMString;
typedef QDateTime ORMDateTime;
typedef QString ORMUuid;
#endif

#ifdef ORMCPPTypes
#include <string>
#include <chrono>
#include "sole/sole.hpp"
typedef std::string ORMString;
typedef std::chrono::system_clock::time_point ORMDateTime;
typedef sole::uuid ORMUuid;
#endif


#endif // ORMDEFINITIONS_H
