#pragma once
#include "SSO.h"


class User{
private:
    String username;
    String password;
    String email;

public:

    User();
    User(String username, String password, String email);


};