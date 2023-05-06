#include "string.h"

void String::free(){
    delete[] _data;
    _data = nullptr;
    _capacity = _size = 0;
}
void String::copyFrom(const String& other){
    _size = other._size;
    _capacity = other._capacity;
    _data = new char[_size + 1];
    strcopy(_data, other._data);
}
String::String(const char c){
    _size = 2;
    _data = new char[2];
    _data[0] = c;
    _data[1] = '\0';

}

String::String(const char* content){
    if(content == nullptr){
        *this = String();
    }
    else {
        _size = strleng(content) + 1;
        _data = new char[_size];
        strcopy(_data, content);
        _capacity = _size * UPSIZE_BY;
    }
}

String::String(): String("\0"){
    
}
String::~String(){
    free();
}

String::String(const String& other){
    copyFrom(other);
}

String& String::operator=(const String& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}
String& String::operator=(const char* other){
    free();
    copyFrom(other);

    return *this;
}
void String::reserve(size_t size){
    if(size > _size){
        resize(size);
    }
}

size_t String::capacity() const{
    return _capacity;
}

size_t String::size() const {
    return _size;
}
size_t String::length() const{
    return _size;
}
const char* String::data() const{
    return _data;
}
char* String::data(){
    return _data;
}
void String::resize(size_t size){

    char* newData = new char[size];
    strcopy_s(newData, size , _data);
    delete[] _data;
    _data = newData;
    _size = size;
    _capacity = _size * UPSIZE_BY;

}
void String::clear(){
    (*this) = "\0";
}

void String::shrink_to_fit(){
    _capacity = _size;    
}


char& String::operator[](size_t size){
    return _data[size];
}

const char& String::operator[](size_t size) const{
    return _data[size];   
}
const char& String::at(size_t size) const{
    if(size > _size)
        throw std::out_of_range("Out of Bounds");
    
    return (*this)[size];
}
char& String::at(size_t size){
    if(size > _size)
        throw std::out_of_range("Out of Bounds");
    
    return (*this)[size];
}
const char& String::front() const{
    if(_data == nullptr)
        throw std::out_of_range("Out of Bounds");

    return (*this)[0];
}
char& String::front() {
    if(_data == nullptr)
        throw std::out_of_range("Out of Bounds");

    return (*this)[0];
}
const char& String::back() const {
    if(_data == nullptr)
        throw std::out_of_range("Out of Bounds");

    return (*this)[_size];
}
char& String::back(){
    if(_data == nullptr)
        throw std::out_of_range("Out of Bounds");

    return (*this)[_size];
}






String& String::operator+=(const String& other){

    char* newString = new char[_size + other._size + 1];
    newString[0] = '\0';

    strconcat(newString, _data);
    strconcat(newString, other._data);

    delete[] _data;
    _size += other._size;
    _data = newString;
    _capacity = _size * UPSIZE_BY;
    
    return *this;
}
String& String::append(const String& other){
    operator+=(other);
    return *this;
}
String& String::push_back(char c){
    if(_capacity <= _size)
        resize(_capacity * UPSIZE_BY);
    
    (*this)[_size++] = c;
    return *this;
}
String& String::assign(const String& str){
    operator=(str);
    return *this;
}
String& String::insert(const String& string, size_t pos){
    if(pos > _size)
        throw std::out_of_range("Out of Bounds");

    size_t newSize = _size + string.size();
    char* newString = new char[newSize + 1];

    strcopy_s(newString, pos, _data );
    strconcat(newString, string.data());
    strconcat(newString, _data + pos);

    (*this) = newString;
    delete[] newString;
    return *this;
}
String& String::erase(size_t pos){
    return erase(pos, 1);

}
String& String::erase(size_t pos, size_t len){
    if(pos + len > _size){
        throw std::out_of_range("Out of Bounds");
    }
    for(size_t i = pos; i < _size; i++){
        _data[i] = _data[i + len];
    }
    _size -= len;
    _data[_size] = '\0';

    if(_size < _capacity / DOWNSIZE_BY){
        resize(_capacity / DOWNSIZE_BY);
    }

    return *this;
}

String& String::replace(size_t pos, size_t len, const String& str){

    if(pos > _size){
        throw std::out_of_range("Out of Bounds");
    }
    size_t newSize = _size - len + str.size();
    char* tempStr = new char[newSize + 1];

    strcopy_s(tempStr, pos, _data);
    strconcat(tempStr, str.data());
    if(pos + len <= _size)
        strconcat(tempStr, _data + pos + len);

    (*this) = tempStr;
    delete[] tempStr;
    
    return *this;
}
void String::swap(String& other){
    String tempStr = other;
    other = *this;
    *this = tempStr;
}
void String::pop_back(){
    _data[_size--] = '\0';
    if(_size < _capacity / DOWNSIZE_BY){
        resize(_capacity / DOWNSIZE_BY);
    }
}



String String::substr(size_t startpos, size_t endpos){
    if(endpos <= startpos){
        return String("\0");
    }

    String newStr(_data + startpos);
    newStr.resize(endpos - startpos);
    return newStr;
}
size_t String::copy(char* destination, size_t pos, size_t len){
    strcopy_s(destination, len, _data + pos);
    return (_size > pos + len)? _size - (pos + len) : pos + len - _size;
}
size_t String::find(const String& string, size_t pos = 0){
    if(pos > _size)
        throw std::out_of_range("Out of Bounds");

    for(size_t i = pos; i < _size; i++){
        if(strfind(_data + i, string.data()))
            return i;
    }
    return nopos;
}
size_t String::rfind(const String& string, size_t pos = 0){
    if(pos > _size || pos == 0)
        throw std::out_of_range("Out of Bounds");

    for(int i = pos; i <= 0; i--){
        if(strfind(_data + i, string.data()))
            return i;
    }
    return nopos;
}
int String::compare(const String& other){
    return strcomp(_data, other.data());    
}





bool String::operator==(const String& other) const{
    return(strcomp(_data, other._data) == 0);
}
bool String::operator!=(const String& other) const{
    return(strcomp(_data, other._data) != 0);
}
bool String::operator<=(const String& other) const{
    return(strcomp(_data, other._data) <= 0);
}
bool String::operator>=(const String& other) const{
    return(strcomp(_data, other._data) >= 0); 
}
bool String::operator<(const String& other) const{
    return(strcomp(_data, other._data) <= 0);
}
bool String::operator>(const String& other) const{
    return(strcomp(_data, other._data) >= 0); 
}
bool String::empty() const{
    return _size == 0;
}
String::operator bool() const{
    return (_data == nullptr || _size == 0);
}



std::ostream& operator<<(std::ostream& os, const String& str){
    os<<str._data;
    return os;
}
std::istream& operator>>(std::istream& is, const String& str){
    is>>str._data;
    return is;
}

std::istream& getline(std::istream& is, String& str, char delim = '\n'){
    size_t getPos = is.tellg();
    size_t len = 0;
    for(size_t i {0};; i++){
        if(is.peek() == '\0'){
            len = i;
            break;
        }
        is.seekg(1, std::ios::cur);
    }
    is.seekg(getPos);

    char* tempChar = new char[len];

    is.getline(tempChar, len, delim);
    str = tempChar;

    delete[] tempChar;

    return is;
}

String operator+ (const String& lhs, const String& rhs){
    String newString = lhs;
    newString += rhs;
    return newString;
}
