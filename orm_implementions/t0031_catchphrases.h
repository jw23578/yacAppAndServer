#ifndef T0031_CATCHPHRASES_H
#define T0031_CATCHPHRASES_H

#include "appbaseobject.h"

class t0031_catchphrases : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(catchphrase_id);
    MACRO_STRING_PROPERTY(catchphrase);

public:
    t0031_catchphrases():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(catchphrase_id, DetailID);
        MACRO_ADD_PROPERTY(catchphrase);
    }
    MACRO_CREATE_AND_GETORMNAME(t0031_catchphrases)
};

#endif // T0031_CATCHPHRASES_H
