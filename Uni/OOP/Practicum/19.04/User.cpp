#include "User.h"


User::User(): User("\0", "\0", "\0"){
    

}

User::User(String username, String password, String email){
    this->username = username;
    this->password = password;
    this->email = email;
}

