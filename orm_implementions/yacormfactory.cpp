#include "yacormfactory.h"
#include "t0001_users.h"
#include "t0002_apps.h"
#include "t0003_appuser_profiles.h"
#include "t0009_appuser_logintoken.h"
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

YACORMFactory::YACORMFactory():ORMFactory<YACBaseObject>()
{
    addGhost(new t0001_users);
    addGhost(new t0002_apps);
    addGhost(new t0003_appuser_profiles);
    addGhost(new t0009_appuser_logintoken);
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
}
