#pragma once
#include "String.h"

class User{
private:
    String _firstName;
    String _lastName;
    String _email;
    String _username;
    String _password;

public:

    User() = default;
    User(const String& firstName, const String& lastName, const String& email, const String& username, const String& password);
    User(const String& username);
    User(String&& username);

    void setFirstName(const String& firstName);
    void setLastName(const String& lastName);
    void setEmail(const String& email);
    void setUserName(const String& username);
    void setPassword(const String& password);

    void setFirstName(String&& firstName);
    void setLastName(String&& lastName);
    void setEmail(String&& email);
    void setUserName(String&& username);
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

private:
    String hash(const String& str) const; //For Future password hashing capabilities

};
