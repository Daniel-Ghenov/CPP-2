#include "User.h"

User::User(const String& firstName, const String& lastName, const String& email, const char* username, const String& password):
            _firstName(firstName), _lastName(lastName), _email(email){
    setUserName(username);
    setPassword(password);
}
User::User(const String& username){
    setUserName(username.data());
}
User::User(const char* username){
    setUserName(username);
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


void User::setUserName(const char* username){
    if(this->validUsername(username))
        strcopy(_username ,username);
}


void User::setPassword(const String& password){
    if(this->validPassword(password))
        _password = password;
}

void User::setPassword(String&& password){
    if(this->validPassword(password))
        _password = std::move(password);
}

void User::setPassword(const char* password){
    if(this->validPassword(password))
        _password = password;
}

void User::print() const{
    std::cout<<"First name: "<<_firstName<<std::endl;
    std::cout<<"Last name: "<<_lastName<<std::endl;
    std::cout<<"username: "<<_username<<std::endl;
    std::cout<<"email: "<<_email<<std::endl;

}
void User::printAdmin() const{
    this->print();
}


bool User::validUsername(const char* username) const{

    for(size_t i {0}; i < USERNAME_LEN; i++){
        if(username[i] == '\0')
            return true;
        if(username[i] < 'a' || username[i] > 'z')
            throw std::invalid_argument("Username must contain only lowercase letters");
    }
    throw std::invalid_argument("Username Too Long");
}

bool User::validPassword(const String& password) const{
    bool hasLower = false, hasUpper = false, hasDigit = false;

    for(size_t i {0}; i < password.size(); i++){
        if(hasLower && hasUpper && hasDigit){
            return true;
        }
        if(password[i] >= 'a' && password[i] <= 'z')
            hasLower = true;
        if(password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = true;
        if(password[i] >= '0' && password[i] <= '9')
            hasDigit = true;
    }

    if(!hasLower || !hasDigit || !hasUpper){
        throw std::invalid_argument("Password must contain one uppercase letter, one lowercase letter and one digit");
    }
    return true;
}
