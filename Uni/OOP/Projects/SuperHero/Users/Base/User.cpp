#include "User.h"

User::User(const String& firstName, const String& lastName, const String& email, const String& username, const String& password):
            _firstName(firstName), _lastName(lastName), _email(email), _username(username), _password(password){
    
}
User::User(const String& username): _username(username){
    
}

User::User(String&& username): _username(std::move(username)){
    
}




const String& User::firstName() const{
    return _firstName;
    
}
const String& User::lastName() const{
    return _lastName;
    
}
const String& User::email() const{
    return _email;
    
}
const String& User::username() const{
    return _username;
    
}
const String& User::password() const{
    return _password;
    
}

void User::setFirstName(const String& firstName){
    _firstName = firstName;
}
void User::setFirstName(String&& firstName){
    _firstName = std::move(firstName);
}
void User::setFirstName(const char* firstName){
    _firstName = firstName;
}


void User::setLastName(const String& lastName){
    _lastName = lastName;
}
void User::setLastName(String&& lastName){
    _lastName = std::move(lastName);
}

void User::setLastName(const char* lastName){
    _lastName = lastName;
}


void User::setEmail(const String& email){
    _email = email;
}
void User::setEmail(String&& email){
    _email = std::move(email);
}
void User::setEmail(const char* email){
    _email = email;
}


void User::setUserName(const String& username){
    _username = username;
}

void User::setUserName(String&& username){
    _username = std::move(username);
}
void User::setUserName(const char* username){
    _username = username;
}


void User::setPassword(const String& password){
    _password = password;
}

void User::setPassword(String&& password){
    _password = std::move(password);
}

void User::setPassword(const char* password){
    _password = password;
}

void User::print() const{
    std::cout<<"First name: "<<_firstName<<std::endl;
    std::cout<<"Last name: "<<_lastName<<std::endl;
    std::cout<<"username: "<<_username<<std::endl;
    std::cout<<"email: "<<_email<<std::endl;

}