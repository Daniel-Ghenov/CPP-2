#pragma once

#include "Const.h"
#include "Helper.h"

class String{
private:
    char* _data;
    size_t _size = 0;
    size_t _capacity = DEFAULT_CAP;

    void copyFrom(const String& other);
    void free();

public:

    static const size_t nopos = -1;  //return-value for "no instance found"


    String();   //Big 4 and Constructors
    String(const char* content);
    ~String();
    String(const String& other);
    String(const char c);
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
    String& insert(const String& string, size_t pos);
    String& erase(size_t pos);
    String& erase(size_t pos, size_t len);
    String& replace(size_t pos, size_t len, const String& str);
    void swap(String& other);
    void pop_back();

    String substr(size_t startpos, size_t endpos);  //String Operations
    size_t copy(char* destination, size_t pos, size_t len);
    size_t find(const String& string, size_t pos);
    size_t rfind(const String& string, size_t pos);


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
    friend std::istream& operator>>(std::istream& is, const String& str);
    friend std::istream& getline(std::istream& is, String& str, char delim);
};

std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, const String& str);

std::istream& getline(std::istream& is, String& str, char delim);

String operator+ (const String& lhs, const String& rhs);
