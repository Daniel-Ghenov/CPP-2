#include "Set.h"

void Set::free(){
    
    delete[] set;
    set = nullptr;
    maxNum = 0;
}
void Set::copyFrom(const Set& other){
    set = new uint8_t[other.maxNum / BUCKET_SIZE + 1];
    for(size_t i {0}; i < other.maxNum; i++){
        set[i] = other.set[i];
    } 
    maxNum = other.maxNum;
}
size_t Set::getBucketIdx(size_t number) const {
    return number / 8;

}
size_t Set::getInBucketIdx(size_t number) const {
    return number % 8;
}

Set::Set(size_t size){
    maxNum = size;
    set = new uint8_t[maxNum/ BUCKET_SIZE + 1];
    for(size_t i {0}; i < maxNum / BUCKET_SIZE + 1; i++){
        set[i] = 0;
    }

}
Set::Set(const Set& other){
    copyFrom(other);

}
Set::~Set(){
    free();

}
Set& Set::operator=(const Set& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

void Set::add(size_t number){
    set[getBucketIdx(number)] |= 1 << getInBucketIdx(number) - 1;
}

void Set::remove(size_t number){
    uint8_t mask = 1 << getInBucketIdx(number) - 1;
    if(set[getBucketIdx(number)] & mask){
        set[getBucketIdx(number)] ^ mask;
    }
}  

bool Set::contains(size_t number) const{
    return (set[getBucketIdx(number)] & 1 << (getInBucketIdx(number) - 1));

}
void Set::print() const{
    for(size_t i {0}; i < maxNum; i++){
        if(contains(i))
            std::cout<<i<<' ';
    }

}
void Set::printInMem() const{
    for(size_t i {0}; i < maxNum ; i++){
        std::cout<< contains(i);
    }

}
Set unionSet(const Set& lhs, const Set& rhs){

    assert(lhs.maxNum == rhs.maxNum);

    Set newSet(lhs.maxNum);

    for(size_t i {0}; i < lhs.maxNum / BUCKET_SIZE; i++){
        newSet.set[i] = lhs.set[i] | rhs.set[i];
    }
    return newSet;

}
Set intersectionSet(const Set& lhs, const Set& rhs){
    
    assert(lhs.maxNum == rhs.maxNum);

    Set newSet(lhs.maxNum);

    for(size_t i {0}; i < lhs.maxNum / BUCKET_SIZE; i++){
        newSet.set[i] = lhs.set[i] & rhs.set[i];
    }
    return newSet;

}