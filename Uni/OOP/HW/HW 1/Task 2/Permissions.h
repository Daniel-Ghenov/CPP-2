#pragma once
#include "Const.h"
#include "Rights.h"

struct Permissions{
private:
    Rights permissions[GROUPS_NUM]; // three users make one group of permissions
    char null = '\0';   //we have a null char so that printing is straight-forward
                        //the null is also not a problem as it would be inside the padding of file anyway

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
