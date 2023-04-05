#include "Helper.h"

int strcomp(const char* first, const char* second){

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
    for(size_t i {0};; i++){
        Destination[i] = Source[i];
        if(Source[i] == '\0')
            return;
    }

}
void strcopy_s(char* Destination ,size_t size, const char* Source){
    for(size_t i {0}; i < size; i++){
        Destination[i] = Source[i];
        if(Source[i] == '\0')
            return;
    }
}
void strconcat(char* Destination, const char* Source){
    unsigned nullIdx = 0;
    while(Destination[nullIdx++] != '\0');
    nullIdx--;
    for(size_t i {0} ;; i++){
        Destination[i + nullIdx] = Source[i];
        if(Source[i] == '\0')
            return;
    }

}
unsigned strleng(const char* str){
    unsigned length = 0;
    while(str[length++] != '\0');
    return length - 1;
}
int strfind(const char* findIn, const char* toFind){

    for(size_t i {0};;i++){
        if(toFind[i] == '\0')
            return 0;
        if(findIn[i] < toFind[i] || findIn[i] == '\0'){
            return -1;
        }
        if(findIn[i] > toFind[i]){
            return 1;
        }
    }
}

