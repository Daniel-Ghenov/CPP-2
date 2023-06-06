#include "SetParser.h"

size_t findStringSize(std::ifstream& ifs){

    size_t currPos = ifs.tellg();
    while(ifs.peek() != '\0')
        ifs.seekg(1, std::ios::cur);

    size_t nullPos = ifs.tellg();
    nullPos++;
    ifs.seekg( currPos, std::ios::beg);
    return nullPos - currPos;

}


SharedPtr<Set> setFactory(std::ifstream& ifs){
    uint16_t type;
    uint16_t number;
    
    ifs.read((char*)&number, sizeof(number));
    ifs.read((char*)&type, sizeof(type));

    switch(type){
        case 0:{
            uint32_t arr[MAX__ARR_SIZE];
            ifs.read((char*)arr, sizeof(uint32_t) * number);
            return new ArrSet(arr, number);
        }
        case 1:{
            uint32_t arr[MAX__ARR_SIZE];
            ifs.read((char*)arr, sizeof(uint32_t) * number);

            return new SetByCrit<notDivisible> (ArrSet(arr, number));

        }
        case 2:{
            uint32_t arr[MAX__ARR_SIZE];
            ifs.read((char*)arr, sizeof(uint32_t) * number);

            return new SetByCrit<DivisibleByOne> (ArrSet(arr, number));

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


void printContents(const SharedPtr<Set> &set, uint32_t low, uint32_t high){

    for(uint32_t i = low; i < high; i++){
        if(set->contains(i))
            std::cout<<i<<", ";
    }
    std::cout<<std::endl;
}
void printNext(const SharedPtr<Set> &set, uint32_t first){
    char cont = true;
    std::cout<<"The first Number is: ";
    while(1){
        while(1){
            if(set->contains(first)){
                std::cout<<first<<std::endl;
                break;
            }
            first++;
        }
        std::cout<<"would you like the next number?(y/n)";
        std::cin>>cont;
        if(cont == 'y'){
            std::cout<<"Next number is: ";
            first++;
        }
        else
            break;
    }
}