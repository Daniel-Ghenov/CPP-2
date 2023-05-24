#include "SetParser.h"

int main(){
    std::ifstream ifs("set.dat", std::ios::in | std::ios::binary);
    SharedPtr<Set> set = setFactory(ifs);
    uint32_t low, high;

    std::cin>>low;
    printNext(set, low);
    

    return 0;
}
