#pragma once
#include "Const.h"
#include "Rights.h"

struct Permissions{
private:
    Rights permissions[GROUPS_NUM];
    char null = '\0';
    int charToGroup(char group) const;
    
public:
    Permissions() = default;
    Permissions(const char* permissions);
    void setPermission(char group, char right, bool set);
    void setPermissions(const char* permissions);
    const char* getPermissions() const;
    bool getPermission(char group , char right) const;
    void print() const;
};
