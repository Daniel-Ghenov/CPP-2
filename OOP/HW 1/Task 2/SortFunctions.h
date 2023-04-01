#pragma once
#include "File.h"

namespace Sort{
    bool sortByName(const File& file1, const File& file2);
    bool sortByCreate(const File& file1, const File& file2);
    bool sortByEdit(const File& file1, const File& file2);
    bool sortBySize(const File& file1, const File& file2);

}