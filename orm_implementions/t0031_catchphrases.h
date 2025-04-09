#ifndef T0031_CATCHPHRASES_H
#define T0031_CATCHPHRASES_H

#include "yacbaseobject.h"

class t0031_catchphrases : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
    MACRO_STRING_PROPERTY(catchphrase);

public:
    t0031_catchphrases():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(catchphrase);
    }
    MACRO_CREATE_AND_GETORMNAME(t0031_catchphrases)
};

#endif // T0031_CATCHPHRASES_H
