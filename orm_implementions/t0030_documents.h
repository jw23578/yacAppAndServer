#ifndef T0030_DOCUMENTS_H
#define T0030_DOCUMENTS_H

#include "yacbaseobject.h"

class t0030_documents : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
    MACRO_UUID_PROPERTY(creater_id);
    MACRO_UUID_PROPERTY(document_blob_id);
    MACRO_UUID_PROPERTY(document_id);
    MACRO_INT_PROPERTY(document_version);
    MACRO_STRING_PROPERTY(document_name);
    MACRO_STRING_PROPERTY(document_type);
    MACRO_STRING_PROPERTY(document_description);
    MACRO_DATETIME_PROPERTY(created_datetime);
    MACRO_DATETIME_PROPERTY(delete_after_datetime);
    MACRO_INT_PROPERTY(document_size);
    MACRO_DATETIME_PROPERTY(deleted_datetime);
    MACRO_UUID_PROPERTY(deleted_appuser_id);

    MACRO_STRING_PROPERTY(transfer_document_base64);
    MACRO_STRING_PROPERTY(transfer_comma_separated_catchphrases_base64);
public:
    t0030_documents():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(creater_id);
        MACRO_ADD_PROPERTY(document_blob_id);
        MACRO_ADD_PROPERTY(document_id);
        MACRO_ADD_PROPERTY(document_version);
        MACRO_ADD_PROPERTY(document_name);
        MACRO_ADD_PROPERTY(document_type);
        MACRO_ADD_PROPERTY(document_description);
        MACRO_ADD_PROPERTY(created_datetime);
        MACRO_ADD_PROPERTY(delete_after_datetime);
        MACRO_ADD_PROPERTY(document_size);
        MACRO_ADD_PROPERTY(deleted_datetime);
        MACRO_ADD_PROPERTY(deleted_appuser_id);

        MACRO_ADD_TRANSFER_PROPERTY(transfer_document_base64);
        MACRO_ADD_TRANSFER_PROPERTY(transfer_comma_separated_catchphrases_base64);
    }
    MACRO_CREATE_AND_GETORMNAME(t0030_documents)
};

#endif // T0030_DOCUMENTS_H
