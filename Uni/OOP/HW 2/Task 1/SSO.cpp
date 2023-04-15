#include "SSO.h"

String::String(const char* content){
    if(!content)
        throw std::logic_error("Cannot initialize with nullptr");

    size_t len = strleng(content);
    if(len < sizeof(String)){
        setShortSize(len);
        strcopy_s((char*)this, len + 1, content);
    }

    else{    
        setSize(len + 1);
        _data = new char[size() * UPSIZE_BY];
        strcopy(_data, content);
        setCapacity(size() * UPSIZE_BY);
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
String& String::operator=(const char* other){

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
    return (_capacity >> 2) | capacityMask();//bitshifting _capacity and OR it with our mask to get the actual capacity
}

size_t String::size() const {
    if(isShort()){
        return shortSize();
    }
    return _size >> 1 | sizeMask();     //we get the bites from the size without the last and we OR it 
                                        //with the second bit from the _cap Shifted to be the most significant byte 
}


size_t String::length() const{
    return size();
}
const char* String::data() const{
    if(isShort())
        return (char*)this;
    return _data;
}
char* String::data(){
    if(isShort())
        return (char*)this;
    return _data;
}
void String::resize(size_t size){
    
    char* newData = new char[size];
    strcopy_s(newData, size, data());
    
    if(!isShort()){
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
    if(len < sizeof(String)){
        str.shortCopy(data() + startpos, len);
        return str;
    }
    str.setCapacity(len * UPSIZE_BY);
    char* newStr = new char[str.capacity()];
    strcopy_s(newStr, len,  data() + startpos);
    str._data = newStr;
    str.setSize(len);

    return str;
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
    String newString = lhs;
    newString += rhs;
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

void String::copyFrom(const char* string){
    size_t strsize = strleng(string);
    if(strsize < sizeof(String))
        shortCopy(string);

    setCapacity(strsize * UPSIZE_BY);
    _data = new char[capacity()];
    strcopy_s(_data, strsize, string);
    setSize(strsize);

}

void String::shortCopy(const String& other){
    assert(other.isShort());

    setShortSize(other.size());
    strcopy_s((char*)this, sizeof(String) ,other.data());

}

void String::shortCopy(const char* string, size_t size = sizeof(String)){
    assert(size <= sizeof(String));

    if(!isShort()){
        delete[] _data;
    }
    setShortSize(size);
    strcopy_s((char*)this, size, string);   //if we are in a short string we directly copy onto the memory of the string
}


size_t String::sizeMask() const{
    return ((_capacity & (1 << 1)) ^ 1 << 1) << (sizeof(_size) - 2);  
    //Taking the second Bit from _cap and shifting it back once so we get 1 if it is 1 and 0 if it is 0
    //We binaary NOT it so that we can store a '\0' as the last byte of our class;
    //then we bitshift that sizeof(_size) - 2 times so that it becomes the most significant bit in our new number;
}
size_t String::capacityMask() const{
    return( ((_size & 1) << (sizeof(_capacity) - 2)) & (_capacity & 1) <<( sizeof(_capacity) - 1));
        //the least significant byte of _size is our second most significant byte so we bitshift it sizeof(_cap) - 2 times
        //and the least significant byte of _capacity is our the most significant byte of capacity()

}

void String::setSize(size_t size){
    
    _size = ( size << 1) | (_size & 1);
    //saving the last bit of the _size, which is the second most significant bit of capacity()


    _capacity = ((_capacity >> 2) << 2) | (((~size) >> (sizeof(size) - 1)) << 1) | (_capacity & 1);
    //bitshift capacity >> 2 and << 2 to set the last two bits as 0 then OR it with NOT size shifted 
    //so its most significant bit is the inverted of the original size's most significant bit
    //and or it with the least significant bit of _capacity to set that


}

void String::setCapacity(size_t capacity){

    _size = ((_size >> 1) << 1) | ((capacity << 1) >> (sizeof(capacity) - 2));
    //setting the least significant bit of _size to be the second most significant bit of capacity

    _capacity = (capacity << 2) | (_capacity & (1 << 1)) | (capacity >> (sizeof(capacity) - 1));
    //shifting capacity twice then setting the last two bits as the old _capacity second bit
    //and the new most significant bit of our new capacity

}

bool String::isShort() const{
    return (!(_capacity & 3));  //_capacity & 3 gets us the last two bits of capacity
                                    //if they are equal to "00" then size > capacity so the string must be short
                                    //because we store the inverted of size's most significant byte in _capacity
}

void String::setShortSize(size_t size){
    assert(size < sizeof(String));

    setCapacity((sizeof(String) - size - 1) << 2);
    //shifting the size twice so we store the small size in the next to last bits
    //storing the size as sizeof(String) - size so that if size == sizeof(String) - 1 the last byte is a '\0'
}
size_t String::shortSize()const{
    assert(isShort());

    return sizeof(String) - (_capacity >> 2) - 1;
    //the size is stored as sizeof(String) - size - 1;

}


