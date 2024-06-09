#ifndef T0035_BLOBS_H
#define T0035_BLOBS_H

#include "yacbaseobject.h"


MACRO_BEGIN_APP_ORM_OBJECT(t0035_blobs)
MACRO_OID_PROPERTY(blob_oid);
public:
t0035_blobs():YACBaseObject(Rights::RN_everybody)
{
    MACRO_ADD_PROPERTY(blob_oid);
}
};

#endif // T0035_BLOBS_H
