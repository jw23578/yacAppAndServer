#ifndef T0027_APP_IMAGES_H
#define T0027_APP_IMAGES_H

#include "appbaseobject.h"

class t0027_app_images : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_image_id);
    MACRO_OID_PROPERTY(image_oid);
    MACRO_STRING_PROPERTY(hash_value);
    MACRO_INT_PROPERTY(position);
    MACRO_STRING_PROPERTY(transfer_image_base64);
public:
    MACRO_CREATE_AND_GETORMNAME(t0027_app_images)
    t0027_app_images():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(app_image_id, DetailID);
        MACRO_ADD_PROPERTY(image_oid);
        MACRO_ADD_PROPERTY(hash_value);
        MACRO_ADD_PROPERTY(position);

        MACRO_ADD_TRANSFER_PROPERTY(transfer_image_base64);
    }
};

#endif // T0027_APP_IMAGES_H
