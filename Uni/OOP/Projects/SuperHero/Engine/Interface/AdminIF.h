#pragma once
#include "Base\BaseIF.h"

class AdminIF: BaseIF{
private:
    Admin* user;
public:
    AdminIF() = default;
    AdminIF(BaseIF& interFace, const char* username, const String& password);
    AdminIF(const AdminIF& other) = delete;
    AdminIF(AdminIF&&) = delete;
    AdminIF& operator=(const AdminIF& other) = delete;
    AdminIF& operator=(AdminIF&& other) = delete;


    void addPlayer(const String& firstName, const String& lastName, const String& email, const char* username, const String& password);
    void addAdmin(const String& firstName, const String& lastName, const String& email, const char* username, const String& password);
    void removePlayer(const char* username);
    void printInfo(const char* username);
    
    void addHero(const String& firstName, const String& lastName, const String& heroName, size_t power,
                size_t cost, Element element, Stance stance);
};