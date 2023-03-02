#include "rightnumbers.h"

const std::string Rights::Administrator("Administrator");
std::set<int> Rights::allRightNumbers;
const RightNumber Rights::RN_addRightNumberToGroup{1, "Add a Right to a Rightgroup"};
const RightNumber Rights::RN_deleteRightNumberToGroup{2, "Delete a Right from a Rightgroup"};
const RightNumber Rights::RN_insertRightGroup{3, "Add a Rightgroup"};
const RightNumber Rights::RN_updateRightGroup{4, "Change a Rightgroup"};
const RightNumber Rights::RN_deleteRightGroup{5, "Delete a Rightgroup"};
