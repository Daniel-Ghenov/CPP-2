#pragma once
#include <iostream>

int strcomp(const char* first, const char* second);
void strcopy_s(char* Destination,size_t size, const char* Source);
void strcopy(char* Destination, const char* Source);
void strconcat(char* Destination, const char* Source);
void strconcat_s(char* Destination, size_t destSize ,const char* Source);
unsigned strleng(const char* str);
size_t find(const char* toFind, const char* findIn);
size_t length(int a);
char* intToStr(int a);
