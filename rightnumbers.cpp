#include "rightnumbers.h"

const std::string Rights::Administrator("Administrator");
std::set<int> Rights::allRightNumbers;
std::map<int, RightNumber*> Rights::allRightNumberObjects;
const RightNumber Rights::RN_changeRightsGroups{1, "Create, Change and Delete Rightgroups"};
const RightNumber Rights::RN_changeSpaces{2, "Create, Change and Delete Spaces"};
