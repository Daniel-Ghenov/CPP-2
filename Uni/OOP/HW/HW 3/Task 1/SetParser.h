#pragma once

#include <fstream>
#include "UnionSet.h"
#include "IntersectionSet.h"
#include "ArrSet.h"
#include "MyString.h"
#include "SetByCrit.hpp"
#include "Predicate.h"

const int maxFileSize = 1024;

SharedPtr<Set> setFactory(std::ifstream& ifs);
void printContents(const SharedPtr<Set> &set, uint32_t low, uint32_t high);
void printNext(const SharedPtr<Set> &set, uint32_t first);

