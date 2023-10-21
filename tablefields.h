#ifndef TABLEFIELDS_H
#define TABLEFIELDS_H

#include "yacappandservermacros.h"

class TableFields
{
public:
    MACRO_ConstString(id);
    MACRO_ConstString(app_id);
    MACRO_ConstString(data);
    MACRO_ConstString(image_id);
    MACRO_ConstString(message_id);
    MACRO_ConstString(receiver_id);
    MACRO_ConstString(received_datetime);
    MACRO_ConstString(read_datetime);
    MACRO_ConstString(reader_id);
    MACRO_ConstString(fstname);
    MACRO_ConstString(surname);
    MACRO_ConstString(visible_name);
    MACRO_ConstString(task_start);
    MACRO_ConstString(task_end);
    MACRO_ConstString(user_id);
    MACRO_ConstString(task);
    MACRO_ConstString(device_token);
    MACRO_ConstString(public_key_base64);
    MACRO_ConstString(deleted);
    MACRO_ConstString(name);
    MACRO_ConstString(appuser_id);
    MACRO_ConstString(password_hash);
    MACRO_ConstString(user_mood);
    MACRO_ConstString(day_rating);
    MACRO_ConstString(ts);
    MACRO_ConstString(type);
    MACRO_ConstString(creater_id);
    MACRO_ConstString(created);
    MACRO_ConstString(finished);
    MACRO_ConstString(verify_token);
    MACRO_ConstString(verify_token_valid_until);
    MACRO_ConstString(loginemail);
    MACRO_ConstString(verified);
    MACRO_ConstString(searching_fuzzy_allowed);
    MACRO_ConstString(searching_exactly_allowed);
    MACRO_ConstString(login_token_valid_until);
    MACRO_ConstString(login_token);
    MACRO_ConstString(default_duration_in_minutes);
    MACRO_ConstString(color);
    MACRO_ConstString(appointment_id);
    MACRO_ConstString(owner_id);
    MACRO_ConstString(element_id);
    MACRO_ConstString(caption);
    MACRO_ConstString(decription);
    MACRO_ConstString(start_datetime);
    MACRO_ConstString(end_datetime);
    MACRO_ConstString(deleted_datetime);
    MACRO_ConstString(deleted_appuser_id);
    MACRO_ConstString(history_datetime);
    MACRO_ConstString(appointment_group_id);
    MACRO_ConstString(appointment_template_id);
    MACRO_ConstString(max_bookable_count);
    MACRO_ConstString(bookable_since_datetime);
    MACRO_ConstString(bookable_until_datetime);
    MACRO_ConstString(booking_credits);
    MACRO_ConstString(visible_for_everybody);
    MACRO_ConstString(right_group_id);
    MACRO_ConstString(right_number);
    MACRO_ConstString(space_id);
    MACRO_ConstString(automatic);
    MACRO_ConstString(access_code);
    MACRO_ConstString(no_space);
    MACRO_ConstString(requested_datetime);
    MACRO_ConstString(approved_datetime);
    MACRO_ConstString(approved_appuser_id);
    MACRO_ConstString(denied_datetime);
    MACRO_ConstString(denied_appuser_id);
    MACRO_ConstString(result_seen);
    MACRO_ConstString(request_allowed);
    MACRO_ConstString(visible_for_non_members);
    MACRO_ConstString(image_oid);

    TableFields() noexcept {};
};

#endif // TABLEFIELDS_H
