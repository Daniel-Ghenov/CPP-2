#include "SSO.h"

String::String(const char* content){
    if(!content)
        throw std::logic_error("Cannot initialize with nullptr");

    size_t len = strleng(content);

    if(len < sizeof(String)){   //short
        setShortSize(len);
        strcopy_s((char*)this, len + 1, content);
    }

    else{   //normal initialization
        setSize(len + 1);
        _data = new char[size() * UPSIZE_BY];
        strcopy(_data, content);
        setCapacity(size() * UPSIZE_BY);
    }
}
String::String(size_t capacity){
    if(capacity >= sizeof(String)){
        _data = new char[capacity];
        _data[0] = '\0';
        setCapacity(capacity);
    }
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

String& String::operator=(const char* other){   //operator overload so that converting constructor is not used

    free();
    copyFrom(other);
    return *this;
}
void String::reserve(size_t size){

    if(size > this->size()){
        resize(size);
    }
}

size_t String::capacity() const{
    if(isShort()){
        return sizeof(String);
    }
    return (_capacity << 1 )| capacityMask();   //bitshifting _capacity and OR it with our mask to get the actual capacity
}

size_t String::size() const {
    if(isShort()){
        return shortSize();
    }
    return _size >> 1 | sizeMask(); //the most significant byte of _size is actually the most significant byte of _capacity
    //so we bitshift once and Or with sizeMask
}


size_t String::length() const{
    return size();
}

char* String::data(){   //private function for returning the data;
    if(isShort())       //used so we don't check for shortness every time
        return (char*)this; 
    return _data;
}
const char* String::data() const{   //the same as c_str
    if(isShort())
        return (char*)this;
    return _data;
}

const char* String::c_str() const{  //in std:: implementations c_str() == data()
    if(isShort())
        return (char*)this;
    return _data;
}

void String::resize(size_t size){
    
    if(size < sizeof(String)){
        const char* currData = data();
        shortCopy(currData);    //if our new string can be represented as short
                                //we copy it as a short string
        if(!isShort()) 
            delete[] currData;

        return;
    }

    char* newData = new char[size]; 
    strcopy_s(newData, size, data());
    
    if(!isShort()){ //if we resize from being short we shouldn't delete the current data
        delete[] _data;
    }
    _data = newData;
    setSize(size);
    setCapacity(size * UPSIZE_BY);

}
void String::clear(){
    free();
}

void String::shrink_to_fit(){
    setCapacity(size());   
}


char& String::operator[](size_t size){
    return data()[size];
}

const char& String::operator[](size_t size) const{
    return data()[size];   
}

const char& String::at(size_t size) const{
    if(size > this->size())
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
        throw std::logic_error("String has been Deleted");

    return (*this)[0];
}

char& String::front() {
    if(_data == nullptr)
        throw std::logic_error("String has been Deleted");

    return (*this)[0];
}

const char& String::back() const {
    if(_data == nullptr)
        throw std::logic_error("String has been Deleted");


    return (*this)[_size];
}

char& String::back(){
    if(_data == nullptr)
        throw std::logic_error("String has been Deleted");

    return (*this)[_size];
}




String& String::operator+=(const String& other){

    if(isShort() && size() + other.size() < capacity()){
        strconcat((char*)this, other.data());   //if we can keep our string short we just concatenate inside the short string
    }
    else if(size() + other.size() + 1 < capacity()){
        strconcat(data(), other.data());    //if we have the capacity we just concatenate
    }
    else{
        char* newString = new char[(size() + other.size() + 1) * UPSIZE_BY];
        strcopy(newString, data());
        strconcat(newString, other.data()); //else we create a new string and make it the concatenation of our two

        if(!isShort())
            delete[] _data;
        
        _data = newString;
        setSize(size() + other.size());
        setCapacity(size() * UPSIZE_BY);
    }
    
    return *this;
}

String& String::append(const String& other){
    operator+=(other);
    return *this;
}

String& String::push_back(char c){
    if(size() == capacity())
        resize(capacity() * UPSIZE_BY);
    
    (*this)[_size++] = c;
    return *this;
}

String& String::assign(const String& str){
    operator=(str);
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
        resize(_capacity / UPSIZE_BY);
    }
}

String String::substr(size_t startpos, size_t len = nopos){
    if(size() < startpos + len)
        throw std::out_of_range("Out of Bounds");

        
    String str;
    if(len < sizeof(String)){   //if our new string can be represented as short we should do so
        str.shortCopy(data() + startpos, len);
        return str;
    }

    str.setCapacity(len * UPSIZE_BY);   //else we create a new string and return it
    char* newStr = new char[str.capacity()];
    strcopy_s(newStr, len,  data() + startpos);
    str._data = newStr;
    str.setSize(len);

    return str;
}


int String::compare(const String& other){   //comparison operators
    return strcomp(data(), other.data());    
}

bool String::operator==(const String& other) const{
    return(strcomp(data(), other.data()) == 0);
}
bool String::operator!=(const String& other) const{
    return(strcomp(data(), other.data()) != 0);
}
bool String::operator<=(const String& other) const{
    return(strcomp(data(), other.data()) <= 0);
}
bool String::operator>=(const String& other) const{
    return(strcomp(data(), other.data()) >= 0); 
}
bool String::operator<(const String& other) const{
    return(strcomp(data(), other.data()) <= 0);
}
bool String::operator>(const String& other) const{
    return(strcomp(data(), other.data()) >= 0); 
}
bool String::empty() const{
    return size() == 0;
}
String::operator bool() const{
    return (_data == nullptr || empty());
}

std::ostream& operator<<(std::ostream& os, const String& str){
    os<<str.data();
    return os;
}

std::istream& operator>>(std::istream& is, String& str){

    char buffer[CIN_BUFF_SIZE];

    is>>buffer;
    str = buffer;
    return is;
}

std::istream& getline(std::istream& is, String& str, char delim = '\n'){
    
    char buffer[CIN_BUFF_SIZE];

    is.getline(buffer, CIN_BUFF_SIZE, delim);
    str = buffer;
    return is;

}

String operator+ (const String& lhs, const String& rhs){
    size_t newsize = (lhs.size() + rhs.size() + 1);
    newsize = (newsize < sizeof(String))? newsize : newsize * UPSIZE_BY;    //if the new string can be stored as a short string
                                                                            //we will not upsize it so we can not use dynamic memory allocation
    String newString (newsize);
    strcopy(newString.data(), lhs.data());
    strconcat(newString.data(), rhs.data());
    return newString;
}



void String::free(){
    if(!isShort())
        delete[] _data;
    _data = nullptr;
    setCapacity(0);
    setSize(0);
}
void String::copyFrom(const String& other){
    if(other.isShort()){
        shortCopy(other);
    }

    setCapacity(other.capacity());
    setSize(other.size());
    _data = new char[capacity()];
    strcopy(_data, other._data);
}

void String::copyFrom(const char* string){  //overload so we do not go trough converting constructor

    size_t strsize = strleng(string);
    if(strsize < sizeof(String))
        shortCopy(string);

    setCapacity(strsize * UPSIZE_BY);
    _data = new char[capacity()];
    strcopy_s(_data, strsize, string);
    setSize(strsize);

}

void String::shortCopy(const String& other){//copy function for shortStrings;
    assert(other.isShort());

    setShortSize(other.size());
    strcopy_s((char*)this, sizeof(String) ,other.data());

}

void String::shortCopy(const char* string, size_t size = sizeof(String)){   //parameters used so we can be ensured that data will not overflow when using short strings
    assert(size <= sizeof(String));

    if(!isShort()){
        delete[] _data;
    }
    setShortSize(size);
    strcopy_s((char*)this, size, string);   //if we are in a short string we directly copy onto the memory of the string
}


size_t String::sizeMask() const{
    return ((_capacity ^ mostSigBit) & mostSigBit);  
    //The most significant bit in _capacity is actually the most significant bit of our size but reversed so we XOR it
}
size_t String::capacityMask() const{
    return _size & 1;
        //the least significant byte of _size is the least significant bit of capacity

}

void String::setSize(size_t size){
    
    _size = ( size << 1) | (_size & 1);
    //bitshifting the new size and adding the old sizes last bit which is the _capacity bit


    _capacity = ((_capacity << 1) >> 1) | ((size ^ mostSigBit) & mostSigBit);
    //bitshift capacity so the most significant bit is 0 and then we OR with the most significant bit of _size
    //we also XOR the most significant bit of size so it is reversed
    //That way when the two most significant bits of _capacity are "00" => size > capacity => we are in a short string
    
}

void String::setCapacity(size_t capacity){

    _size = ((_size >> 1) << 1) | (capacity & 1);
    //setting the least significant bit of _size to be the least significant bit of capacity

    _capacity = capacity >> 1 | (_capacity & mostSigBit);
    //shifting capacity so we keep the bit of _size

}

bool String::isShort() const{
    return ((_capacity >> ((sizeof(_capacity) * 8) - 2)) == 0) ;   //checking if the two most significant bits of _capacity are "00"
}

void String::setShortSize(size_t size){
    
    assert(size < sizeof(String));  //when we are in a short string the size will be stored in the last byte of String
    //which is the most significant byte in _capacity because we are in little endian

    _capacity = ((_capacity << 8) >> 8) | ((sizeof(String) - size - 1) << ((sizeof(_capacity) * 8) - 8));  //flushing the last 8 bits of _capacity and setting them to the bits of size
    //since short sized strings are at max 23 characters long the 6 bits of the most significant byte of _capacity can hold them all
    //we have sizeof(String - size - 1) so that when the size is 24 the last character is actually /0

}
size_t String::shortSize()const{

    return sizeof(String) - (_capacity >> ((sizeof(_capacity) * 8) - 8)) - 1;
    //the size is stored as sizeof(String) - size - 1;
}


