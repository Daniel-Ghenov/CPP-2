#pragma once
#include <cassert>
#include "Const.h"
#include "Helper.h"

class String{
private:
    char* _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;


public:

    static const size_t nopos = -1;  //return-value for "no instance found"


    String() = default;   //Big 4 and Constructors
    String(const char* content);
    ~String();
    String(const String& other);
    String& operator=(const String& other);
    String& operator=(const char* other);


    char& operator[](size_t size);  //Access Data
    const char& operator[](size_t size) const;
    const char& at(size_t size) const;
    char& at(size_t size);
    const char& back() const;
    const char& front() const;
    char& back();
    char& front();
    const char* data() const;
    char* data();

    size_t size() const;    //Capacity
    size_t length() const;
    size_t capacity() const;
    void resize(size_t size);
    void reserve(size_t size);
    void clear();
    void shrink_to_fit();


    String& operator+=(const String& other);    //Modifiers
    String& append(const String& other);
    String& push_back(char c);
    String& assign(const String& string);
    void swap(String& other);
    void pop_back();

    String substr(size_t startpos, size_t endpos);  //String Operations

    bool operator==(const String& other) const; //Boolean Operations
    bool operator!=(const String& other) const;
    bool operator<=(const String& other) const;
    bool operator>=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    bool empty() const;
    operator bool() const;
    int compare(const String& other);


    friend std::ostream& operator<<(std::ostream& os, const String& str);   //Stream Operations
    friend std::istream& operator>>(std::istream& is, String& str);
    friend std::istream& getline(std::istream& is, String& str, char delim);

private: 

    void shortCopy(const char* string, size_t size);
    void shortCopy(const String& other);
    void copyFrom(const char* string);
    void copyFrom(const String& other);
    void free();


    bool isShort() const;
    size_t sizeMask() const;
    size_t capacityMask() const;
    void setSize(size_t size);
    void setCapacity(size_t capacity);
    void setShortSize(size_t size);
    size_t shortSize()const;

};

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, const String& str);

std::istream& getline(std::istream& is, String& str, char delim);

String operator+ (const String& lhs, const String& rhs);
