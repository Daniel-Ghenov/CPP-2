#pragma once
#include "Const.h"
#include "TimeDate.h"
#include "Permissions.h"

class File{
private:
    char name[MAX_NAME_LEN] = "";
    char content[MAX_CONTENT_LEN];
    Permissions permissions;
    size_t size = 0;
    TimeDate createTime;
    TimeDate editTime;
public:
    File();
    File(const char* name, unsigned createDay, unsigned createMonth, unsigned createYear,
    unsigned creatHours, unsigned createMins, unsigned createSeconds, const char* permissions);

    void setName(const char* name);
    void setContent(const char* content);
    void setSize();
    void setPermission(char group, char right, bool set);
    const char* getName() const;
    const char* getContent()const;
    bool getPermission(char group , char right) const;
    const char* getPermissions()const;
    const TimeDate& getCreate() const;
    const TimeDate& getEdit() const;
    size_t getSize() const;
    void printContent(char group) const;
    void printInfo() const;
    void addContent(const char* content);
    void setEdit(unsigned editDay, unsigned editMonth, unsigned editYear,
                unsigned editHours, unsigned editMins, unsigned editSeconds);
    void deleteFile();

};