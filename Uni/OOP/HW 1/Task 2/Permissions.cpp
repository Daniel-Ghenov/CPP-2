#include "Permissions.h"

int Permissions::charToGroup(char group) const{
    if(group == 'u')
        return 0;
    if(group == 'g')
        return 1;
    if(group == '0')
        return 2;
    return -1;
}
Permissions::Permissions(const char* permissions){
    setPermissions(permissions);
}
void Permissions::setPermission(char group, char right, bool set){
    if(charToGroup(group) == -1)
        return;
    permissions[charToGroup(group)].setRight(right, set);
}
void Permissions::setPermissions(const char* permissions){
    for(size_t i {0}; i < GROUPS_NUM; i++){
        this->permissions[i].setRights(permissions);
        permissions += 3;
    }
}
const char* Permissions::getPermissions() const{
    return (char *)this;
}
bool Permissions::getPermission(char group , char right) const{
    if(charToGroup(group) == -1)
        return false;
    return (permissions[charToGroup(group)].hasRight(right));
}
void Permissions::print() const{
    std::cout<<(char*)permissions;
}