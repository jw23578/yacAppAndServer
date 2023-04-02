#ifndef T0027_APP_IMAGES_H
#define T0027_APP_IMAGES_H

#include "yacbaseobject.h"

class t0027_app_images : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
    MACRO_SIZET_PROPERTY(image_oid);
    MACRO_STRING_PROPERTY(hash_value);
public:
    t0027_app_images():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(image_oid);
        MACRO_ADD_PROPERTY(hash_value);
    }
    const ORMString getORMName() const override
    {
        return "t0027_app_images";
    }
    YACBaseObject *create() const override
    {
        return new t0027_app_images;
    }
};

#endif // T0027_APP_IMAGES_H
