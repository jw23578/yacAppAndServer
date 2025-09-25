#ifndef TABLENAMES_H
#define TABLENAMES_H

#include "yacappandservermacros.h"

class TableNames
{
public:
    MACRO_ConstString(t0010_task);
    MACRO_ConstString(t0011_task_time);
    MACRO_ConstString(t0012_worktime);
    MACRO_ConstString(t0013_images);
    MACRO_ConstString(t0014_message_read);
    MACRO_ConstString(t0015_appuser_devicetoken);
    MACRO_ConstString(t0016_appointment_templates);
    MACRO_ConstString(t0028_message_images);
    MACRO_ConstString(t0029_third_party_user_data);

    // AppUers in the following Table are allowed to use the Element
    // Element can be an AppointmentTemplate for example
    MACRO_ConstString(t0017_element_usable4appuser);

    MACRO_ConstString(t0018_appointment);

    // AppUers in the following Table are allowed to see the Element
    // Element can be an AppointmentTemplate for example
    MACRO_ConstString(t0019_element_visible4appuser);

    MACRO_ConstString(t0020_appointment_participants);

    MACRO_ConstString(t0021_right_group);
    MACRO_ConstString(t0022_right_group2appuser);
    MACRO_ConstString(t0023_right2rightgroup);

    MACRO_ConstString(t0024_space);
    MACRO_ConstString(t0025_space2appuser);

    MACRO_ConstString(t0030_documents);
    MACRO_ConstString(t0031_catchphrases);
    MACRO_ConstString(t0032_catchprase2document);
    MACRO_ConstString(t0033_words);
    MACRO_ConstString(t0034_word2document);

    TableNames() noexcept {};
};


#endif // TABLENAMES_H
