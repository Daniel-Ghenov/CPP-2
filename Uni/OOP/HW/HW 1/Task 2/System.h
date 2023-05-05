#pragma once
#include "SortFunctions.h"
#include <algorithm>

typedef bool (*shouldSwap)(const File& file1, const File& file2);

enum class SortOptions{
    name,
    creationTime,
    editTime,
    size
};

class System{
private:
    File* files = nullptr;
    size_t currSize = 0;
    size_t maxSize = 0;

    int findName(const char* name) const;
    shouldSwap returnSortFunc(SortOptions option);
    void copyFrom(const System& other);
    void free();

public:
    System(size_t size);
    ~System();
    void addFile(const char* name, unsigned editDay, unsigned createMonth, unsigned createYear,
        unsigned creatHours, unsigned createMins, unsigned createSeconds, const char* permissions);

    void editFile(const char* name, const char* content, unsigned editDay, unsigned editMonth, unsigned editYear,
                          unsigned editHours, unsigned editMins, unsigned editSeconds, char user);

    void addInFile(const char* name, const char* content, unsigned editDay, unsigned editMonth, unsigned editYear,
                          unsigned editHours, unsigned editMins, unsigned editSeconds, char user);

    void deleteFile(const char* name, char user);
    void editRights(const char* name, char group, char right);
    void printContent(const char* name, char group);
    void printInfo(const char* name);
    void print();
    void sort(SortOptions sort);
    System& operator=(const System& other);
    System(const System& other);
   
};