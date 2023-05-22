#include <fstream>
#include "UnionSet.h"
#include "IntersectionSet.h"
#include "ArrSet.h"
#include "MyString.h"
#include "SetByCrit.hpp"

const int maxFileSize = 1024;

size_t findStringSize(std::ifstream&ifs){

    size_t size = ifs.tellg();
    while(ifs.peek() != '\0'){
        ifs.seekg(1, std::ios::cur);
    }
    size_t diff = ifs.tellg() - size;
    ifs.seekg(size);
    return diff;
}

SharedPtr<Set> setFactory(std::ifstream& ifs){
    uint16_t type;
    uint16_t number;
    
    ifs.read((char*)&type, sizeof(type));
    ifs.read((char*)&number, sizeof(number));

    switch(type){
        case 0:{
            uint32_t arr[MAX__ARR_SIZE];
            ifs.read((char*)arr, sizeof(uint32_t) * number);
            return new ArrSet(arr, number);
        }
        case 1:{
            uint32_t arr[MAX__ARR_SIZE];    //maybe some way to create lambda function with ArrSet????
            ifs.read((char*)arr, sizeof(uint32_t) * number);
            return new ArrSet(arr, number);
        }
        case 3: {
            Vector<SharedPtr<Set>> temp;

            for(size_t i {0}; i < number; i++){
                size_t size = findStringSize(ifs);
                String fileName(size);
                ifs.read(fileName.data(), size);

                std::ifstream newFile(fileName.data(), std::ios::in | std::ios::binary);
                temp.push_back(setFactory(newFile));
            }
            return new UnionSet(std::move(temp));
        }
        case 4: {
            Vector<SharedPtr<Set>> temp;

            for(size_t i {0}; i < number; i++){
                size_t size = findStringSize(ifs);
                String fileName(size);
                ifs.read(fileName.data(), size);

                std::ifstream newFile(fileName.data(), std::ios::in | std::ios::binary);
                temp.push_back(setFactory(newFile));
            }

            return new IntersectionSet(std::move(temp));
        }

        default:
            return nullptr;
    }
}