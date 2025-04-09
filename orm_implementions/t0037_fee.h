#ifndef T__37_FEE_H
#define T__37_FEE_H

#include "yacbaseobject.h"

class t0037_fee : public YACBaseObject
{
    Q_OBJECT

    MACRO_UUID_PROPERTY(app_id);
    MACRO_UUID_PROPERTY(t0036_id);
    MACRO_INT_PROPERTY(fee);
    MACRO_INT_PROPERTY(fee_currency);
public:
    enum FeeCurrencys
    {
        none,
        euro_cent
    };
    MACRO_CREATE_AND_GETORMNAME(t0037_fee)
    t0037_fee():YACBaseObject(Rights::RN_everybody)
    {
        setfee_currency(euro_cent);

        MACRO_ADD_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(t0036_id);
        MACRO_ADD_PROPERTY(fee);
        MACRO_ADD_PROPERTY(fee_currency);
    }
};

#endif // T__37_FEE_H
