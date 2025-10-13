#ifndef T0035_BLOBS_H
#define T0035_BLOBS_H

#include "appbaseobject.h"


class t0035_blobs: public AppBaseObject
{
    Q_OBJECT
    MACRO_UUID_PROPERTY(blob_id);
    MACRO_OID_PROPERTY(blob_oid);
public:
    MACRO_CREATE_AND_GETORMNAME(t0035_blobs)
    t0035_blobs():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(blob_id, DetailID);
        MACRO_ADD_PROPERTY(blob_oid);
    }
};

#endif // T0035_BLOBS_H
