#include "StringAlg.h"

size_t find(const char* find, const char* findIn){
    size_t findLen = strleng(find);
    size_t findInLen = strleng(findIn);

    RollingHash findInHash(findIn, findInLen);
    RollingHash findHash(find, findInLen);

    for(size_t i {0}; i < findLen - findInLen;i++){
        if(findInHash == findHash)
            return i;
        else{
            findHash.pop_back();
            findHash.push_front(find[i + findInLen]);
        }
    }
    return -1;

}
