#ifndef T___9_LARGEOBJECT_H
#define T___9_LARGEOBJECT_H

#include "appbaseobject.h"

class t0009_largeobject : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
public:
    enum LargeObjectType
    {
        LOTunknown = 0,
        LOTanyTmageType,
        LOTanyDocumentType
    };
    enum LargeObjectMeaning
    {
        LOMunknown = 0, // not allowed
        LOMAppImage
    };

private:
    MACRO_UUID_PROPERTY(largeobject_id);
    MACRO_UUID_PROPERTY(database_blob_id);
    MACRO_INT_PROPERTY(byte_size);
    MACRO_INT_PROPERTY(pixel_width);
    MACRO_INT_PROPERTY(pixel_height);
    MACRO_STRING_PROPERTY(hash_value);
    MACRO_STRING_PROPERTY(transfer_base64);
    MACRO_INT_PROPERTY(large_object_type);
    MACRO_INT_PROPERTY(large_object_meaning);
public:
    MACRO_CREATE_AND_GETORMNAME(t0009_largeobject)
    t0009_largeobject():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(largeobject_id, DetailID);
        MACRO_ADD_PROPERTY(database_blob_id);
        MACRO_ADD_PROPERTY(byte_size);
        MACRO_ADD_PROPERTY(pixel_width);
        MACRO_ADD_PROPERTY(pixel_height);
        MACRO_ADD_PROPERTY(large_object_type);
        MACRO_ADD_PROPERTY(large_object_meaning);

        MACRO_ADD_TRANSFER_PROPERTY(transfer_base64);
    }
};

#endif // T___9_LARGEOBJECT_H
