#include "SortFunctions.h"

bool Sort::sortByName(const File& file1, const File& file2){    //functions to use in the sorting method
    return (strcmp(file1.getName(), file2.getName()) > 0); 
}
bool Sort::sortByCreate(const File& file1, const File& file2){
    return (file1.getCreate().compare(file2.getCreate()) > 0);
}

bool Sort::sortByEdit(const File& file1, const File& file2){
    return (file1.getEdit().compare(file2.getEdit()) > 0);
}

bool Sort::sortBySize(const File& file1, const File& file2){
    return (file1.getSize() > file2.getSize());
}

