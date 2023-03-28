#pragma once
#include "SortFunctions.h"
#include <algorithm>

typedef bool (* shouldSwap)(const File& file1, const File& file2);

enum class SortOptions{
    name,
    creationTime,
    editTime,
    size
};

class System{
private:
    File* files;
    size_t currSize = 0;
    size_t maxSize;
    int findName(const char* name) const;
    shouldSwap returnSortFunc(SortOptions option);
public:
    System();
    System(size_t size);
    ~System();
    void addFile(const char* name, size_t editDay, size_t createMonth, size_t createYear,
        size_t creatHours, size_t createMins, size_t createSeconds, const char* permissions);

    void editFile(const char* name, const char* content, size_t editDay, size_t editMonth, size_t editYear,
                          size_t editHours, size_t editMins, size_t editSeconds, char user);

    void addInFile(const char* name, const char* content, size_t editDay, size_t editMonth, size_t editYear,
                          size_t editHours, size_t editMins, size_t editSeconds, char user);

    void deleteFile(const char* name);
    void editRights(const char* name, char group, char right);
    void printContent(const char* name, char group);
    void printInfo(const char* name);
    void print();
    void sort(SortOptions sort);

};