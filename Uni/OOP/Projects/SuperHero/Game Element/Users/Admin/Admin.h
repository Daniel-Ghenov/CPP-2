#pragma once
#include "../Base\User.h"

class Admin: public User{

public:
    Admin() = default;
    Admin(const String& firstName, const String& lastName, const String& email, const char* username, const String& password);
    
    
};