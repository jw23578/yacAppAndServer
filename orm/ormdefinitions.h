#ifndef ORMDEFINITIONS_H
#define ORMDEFINITIONS_H

#include "JWUtils/definitions.h"

enum ORMPropertyDetails
{
    DetailDB,
    DetailDBPrimaryKey,
    DetailDBSystemInfo,
    DetailDBHstoriedDateTime,
    DetailDBDeletedDateTime,
    DetailID,
    DetailDBIndex,
    DetailOnlyTransfer,
    DetailDontTransfer
};

#endif // ORMDEFINITIONS_H
