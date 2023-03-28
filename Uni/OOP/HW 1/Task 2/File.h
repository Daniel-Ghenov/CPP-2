#pragma once
#include "Const.h"
#include "CompleteDate.h"
#include "Permissions.h"

class File{
private:
    char name[MAX_NAME_LEN] = "";
    char content[MAX_CONTENT_LEN];
    Permissions permissions;
    size_t size = 0;
    CompleteDate createTime;
    CompleteDate editTime;
public:
    File();
    File(const char* name, size_t createDay, size_t createMonth, size_t createYear,
    size_t creatHours, size_t createMins, size_t createSeconds, const char* permissions);

    void setName(const char* name);
    void setContent(const char* content);
    void setSize();
    void setPermission(char group, char right, bool set);
    const char* getName() const;
    const char* getContent()const;
    bool getPermission(char group , char right) const;
    const char* getPermissions()const;
    const CompleteDate& getCreate() const;
    const CompleteDate& getEdit() const;
    size_t getSize() const;
    void printContent(char group) const;
    void printInfo() const;
    void addContent(const char* content);
    void setEdit(size_t editDay, size_t editMonth, size_t editYear,
                size_t editHours, size_t editMins, size_t editSeconds);
    void deleteFile();

};