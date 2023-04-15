#pragma once
#include <iostream>

int strcomp(const char* first, const char* second);
void strcopy_s(char* Destination,size_t size, const char* Source);
void strcopy(char* Destination, const char* Source);
void strconcat(char* Destination, const char* Source);
unsigned strleng(const char* str);