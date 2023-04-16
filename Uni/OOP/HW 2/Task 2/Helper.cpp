#include "Helper.h"

int strcomp(const char* first, const char* second){
    if(!first || !second)
        throw std::logic_error("Cannot process nullptr");


    for(size_t i {0};;i++){
        if(first[i] < second[i]){
            return -1;
        }
        if(first[i] > second[i]){
            return 1;
        }
        if(first[i] == second[i] && first[i] == '\0')
            return 0;
    }

}
void strcopy(char* Destination, const char* Source){
    if(!Destination || !Source)
        throw std::logic_error("Cannot process nullptr");

    for(size_t i {0};; i++){
        Destination[i] = Source[i];
        if(Source[i] == '\0')
            return;
    }

}
void strcopy_s(char* Destination ,size_t size, const char* Source){
    if(!Destination || !Source)
        throw std::logic_error("Cannot process nullptr");

    for(size_t i {0}; i < size; i++){
        Destination[i] = Source[i];
        if(Source[i] == '\0')
            return;
    }
    Destination[size - 1] = '\0';
}
void strconcat(char* Destination, const char* Source){
    if(!Destination || !Source)
        throw std::logic_error("Cannot process nullptr");

    unsigned nullIdx = 0;
    while(Destination[nullIdx++] != '\0');
    nullIdx--;
    
    for(size_t i {0} ;; i++){        
        Destination[i + nullIdx] = Source[i];
        if(Source[i] == '\0')
            return;
    }

}
void strconcat_s(char* Destination, size_t destSize ,const char* Source){
    if(!Destination || !Source)
        throw std::logic_error("Cannot process nullptr");

    unsigned nullIdx = 0;
    while(Destination[nullIdx++] != '\0');
    nullIdx--;
    
    for(size_t i {0} ; i + nullIdx < destSize; i++){
        Destination[i + nullIdx] = Source[i];
        if(Source[i] == '\0')
            return;
    }
    Destination[destSize] = '\0';

}
unsigned strleng(const char* str){
    if(!str)
        throw std::logic_error("Cannot process nullptr");

    unsigned length = 0;
    while(str[length++] != '\0');
    return length - 1;
}
size_t find(const char* findIn, const char* toFind){
    if(!toFind || !findIn)
        throw std::logic_error("Cannot process nullptr");

    size_t toFindLen = strleng(toFind);
    size_t findInLen = strleng(findIn);

    for(size_t i {0}; i < findInLen; i++){
        for(size_t j {0}; j <= findInLen; j++){
            if(j == findInLen)
                return i;
            if(findIn[i + j] != toFind[j]){
                break;
            }

        }
    }
    return -1;
}
size_t length(int a){
    size_t len = 1;
    while(a /= 10){
        len++;
    }
    return len;
}
char* intToStr(int a){

    size_t counter = (a < 0)? length(a) + 1 : length(a);
    
    char* newStr = new char[counter + 1];
    newStr[counter] = '\0';
 
    while(counter--){
        if(a == 0){
            newStr[0] = '-';
            break;
        }
         
        newStr[counter] = '0' + a % 10;
        a /= 10;
    }
    return newStr;
    
}

