#pragma once
#include "MyString.h"

const int USERNAME_LEN = 17;
const int NAME_LEN = 21;
const int EMAIL_LEN = 41;
const int PASS_LEN = 25;

class User{
private:
    String _firstName;
    String _lastName;
    String _email;
    String _password;
    char _username[USERNAME_LEN];

public:

    User() = default;
    User(const String& firstName, const String& lastName, const String& email, const char* username, const String& password);
    User(const String& username);
    User(const char* username);

    void setFirstName(const String& firstName);
    void setLastName(const String& lastName);
    void setEmail(const String& email);
    void setPassword(const String& password);

    void setFirstName(String&& firstName);
    void setLastName(String&& lastName);
    void setEmail(String&& email);
    void setPassword(String&& password);

    void setFirstName(const char* firstName);
    void setLastName(const char* lastName);
    void setEmail(const char* email);
    void setUserName(const char* username);
    void setPassword(const char* password);

    const String& firstName() const;
    const String& lastName() const;
    const String& email() const;
    const String& username() const;
    const String& password() const;

    virtual void print() const;
    virtual void printAdmin() const;

private:
    String hash(const String& str) const; //For Future password hashing capabilities
    bool validUsername(const char* username) const;
    bool validPassword(const String& password) const;

};