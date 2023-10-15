#include <iostream>


int charCountInWord(std::string str, int charCount, char ch ){
    int count = 0;
    int size = str.length();
    int remainder = charCount % size;
    int fullCount = charCount / size;

    for(int i = 0; i < size; i++){
        if(str[i] == ch && i < remainder){
            count += fullCount + 1;
        }else if(str[i] == ch){
            count += fullCount;
        }
    }

    return count;
}

int main() {

    std::string str;
    int charCount;
    char ch;
    std::cin>>str>>charCount>>ch;
    std::cout<<charCountInWord(str, charCount, ch);
    return 0;
}