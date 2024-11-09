#ifndef T0035_BLOBS_H
#define T0035_BLOBS_H

#include "yacbaseobject.h"


class t0035_blobs: public YACBaseObject
{
    Q_OBJECT
    MACRO_UUID_PROPERTY(app_id);
MACRO_OID_PROPERTY(blob_oid);
public:
MACRO_CREATE_AND_GETORMNAME(t0035_blobs)
t0035_blobs():YACBaseObject(Rights::RN_everybody)
{
    MACRO_ADD_PROPERTY(blob_oid);
}
};

#endif // T0035_BLOBS_H
