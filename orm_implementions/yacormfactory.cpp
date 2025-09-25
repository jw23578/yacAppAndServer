#include "yacormfactory.h"
#include "t0001_apps.h"
#include "t0002_user.h"
#include "t0003_user_passwordhashes.h"
#include "t0004_user_logintoken.h"
#include "t0005_group_of_appusers.h"
#include "t0006_appuser2group.h"
#include "t0007_messages.h"
#include "t0008_message_received.h"
#include "t0016_appointment_templates.h"
#include "t0018_appointment.h"
#include "t0021_right_group.h"
#include "t0022_right_group2appuser.h"
#include "t0023_right2rightgroup.h"
#include "t0026_appuser_tag.h"
#include "t0027_app_images.h"
#include "t0028_message_images.h"
#include "t0029_third_party_user_data.h"
#include "t0030_documents.h"
#include "t0031_catchphrases.h"
#include "t0032_catchphrase2document.h"
#include "t0033_words.h"
#include "t0034_word2document.h"
#include "t0035_blobs.h"
#include "t0036_rythm.h"
#include "t0037_fee.h"


YACORMFactory::YACORMFactory():ORMFactory<YACBaseObject>()
{
    addGhost(new t0001_apps);
    addGhost(new t0002_user);
    addGhost(new t0003_user_passwordhashes);
    addGhost(new t0004_user_logintoken);
    addGhost(new t0005_group_of_appusers);
    addGhost(new t0006_appuser2group);
    addGhost(new t0007_messages);
    addGhost(new t0008_message_received);
    addGhost(new t0016_appointment_templates);
    addGhost(new t0018_appointment);
    addGhost(new t0021_right_group);
    addGhost(new t0022_right_group2appuser);
    addGhost(new t0023_right2rightgroup);
    addGhost(new t0026_appuser_tag);
    addGhost(new t0027_app_images);
    addGhost(new t0028_message_images);
    addGhost(new t0029_third_party_user_data);
    addGhost(new t0030_documents);
    addGhost(new t0031_catchphrases);
    addGhost(new t0032_catchphrase2document);
    addGhost(new t0034_word2document);
    addGhost(new t0033_words);
    addGhost(new t0035_blobs);
    addGhost(new t0036_rythm);
    addGhost(new t0037_fee);
}
