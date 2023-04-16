#include "String Creator.h"


StringCreator::StringCreator(size_t count){
    pieces = new StringPiece[count];
    capacity = count;
}

StringCreator::~StringCreator(){
    free();
}

StringCreator::StringCreator(const StringCreator& other){
    copyFrom(other);
}

StringCreator& StringCreator::operator=(const StringCreator& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}


void StringCreator::addPiece(const StringPiece& piece){
    if(size == capacity){
        resize(capacity * UPSIZE_BY);
    }
    pieces[size++] = piece;
}

void StringCreator::addPiece(){
    if(size == capacity){
        resize(capacity * UPSIZE_BY);
    }
    pieces[size++] = "\0";
}

void StringCreator::swap(size_t index1 , size_t index2){
    if(index1 > size || index2 > size)
        throw std::out_of_range("Out of Range");

    Swap(pieces[index1], pieces[index2]);
}

void StringCreator::remove(size_t index){
    if(index >= size)
        throw std::out_of_range("Index out of range");

    pieces[index].setContent("\0");

}

void StringCreator::add(size_t index, const StringPiece& piece){
    if(index > size)
        throw std::out_of_range("Index out of range");

    if(index == size){
        addPiece(piece);
        return;
    }
    pieces[index] = piece;
}


size_t StringCreator::getSize() const{
    return size;
}

size_t StringCreator::getLength() const{
    size_t len = 0;
    for(size_t i {0}; i < size; i++){
        if(pieces[i].getSize() == 0)
            len += EMPTY_STR_LEN - 1;   //returns the length of the whole String
        len += pieces[i].getSize();
    }
    return len;
}
String StringCreator::getString()const{
    size_t length = getLength();
    char* StringContent = new char[length + 1];
    StringContent[0] = '\0';

    for(size_t i {0}; i < size; i++){
        if(pieces[i].getSize() == 0){
            strconcat(StringContent, EMPTY_STRING); //empty Strings get replaced by 20 spaces
        }else{
            strconcat(StringContent, pieces[i].getContent());
        }
    }
    String newStr = StringContent;

    delete[] StringContent;
    return newStr;

}

StringPiece& StringCreator::operator[](size_t index){
    if(index > size)
        throw std::out_of_range("Out of Range");

    return pieces[index];
}


void StringCreator::free(){
    delete[] pieces;
    pieces = nullptr;
    capacity = size = 0;
}

void StringCreator::copyFrom(const StringCreator& other){
    capacity = other.capacity;
    pieces = new StringPiece[capacity];
    size = other.size;

    for(size_t i {0}; i < size; i++){
        pieces[i] = other.pieces[i];
    }
}

void StringCreator::resize(size_t newCap){
    
    StringPiece* newPieces = new StringPiece[newCap];
    size = (newCap > size)? size : newCap;   //if we upsize we cycle to newCap else we cycle to size

    for(size_t i {0}; i < size; i++){ 
        newPieces[i] = pieces[i];
    }
    delete[] pieces;
    pieces = newPieces;
    capacity = newCap;



}

