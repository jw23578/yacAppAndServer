#ifndef T0028_MESSAGE_IMAGES_H
#define T0028_MESSAGE_IMAGES_H

#include "yacbaseobject.h"

class t0028_message_images : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
    MACRO_OID_PROPERTY(image_oid);
    MACRO_UUID_PROPERTY(creater_id);
    MACRO_INT_PROPERTY(width);
    MACRO_INT_PROPERTY(height);
    MACRO_STRING_PROPERTY(transfer_image_base64);
public:
    t0028_message_images():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(image_oid);
        MACRO_ADD_PROPERTY(creater_id);
        MACRO_ADD_PROPERTY(width);
        MACRO_ADD_PROPERTY(height);

        MACRO_ADD_TRANSFER_PROPERTY(transfer_image_base64);
    }
    const ORMString getORMName() const override
    {
        return "t0028_message_images";
    }
    YACBaseObject *create() const override
    {
        return new t0028_message_images;
    }
};

#endif // T0028_MESSAGE_IMAGES_H
