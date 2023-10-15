    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>

    const int MAX_INT = 63;
    const int INT_INTERVAL = 11;
    const int SMALL_LETTER_INTERVAL = 37;

    void countingSort(unsigned* arr, size_t size){  //sortIn is an array that has the same size as arr

        if(size == 0)
            return;

        unsigned max = MAX_INT;
        unsigned* countArr = new unsigned[max + 1];

        for(size_t i = 0; i <= max; i++){
            countArr[i] = 0;
        }

        for(size_t i = 0; i < size; i++){
            countArr[arr[i]]++; //we count the instances of any number found
        }

        for(size_t i = 1; i < INT_INTERVAL; i++){
            for(size_t j = 0; j < countArr[i]; j++){
                std::cout<< i - 1;
            }
        }

        for(size_t i = INT_INTERVAL; i < SMALL_LETTER_INTERVAL; i++){
            for(size_t j = 0; j < countArr[i]; j++){
                std::cout<< char(i - INT_INTERVAL + 'a');
            }
        }

        for(size_t i = SMALL_LETTER_INTERVAL; i < MAX_INT; i++) {
            for (size_t j = 0; j < countArr[i]; j++) {
                std::cout << char (i - SMALL_LETTER_INTERVAL + 'A');
            }
        }

        delete[] countArr;

    }


    int main(){
        int size;
        std::cin>>size;
        std::string str;
        unsigned* arr = new unsigned[size];
        std::cin>>str;
        for(int i = 0; i < size; i++){
            if(str[i] >= '0' && str[i] <= '9'){
                arr[i] = str[i] - '0' + 1;
            }
            else if(str[i] >= 'a' && str[i] <= 'z'){
                arr[i] = str[i] - 'a' + INT_INTERVAL;
            }
            else{
                arr[i] = str[i] - 'A' + SMALL_LETTER_INTERVAL;
            }

        }

        countingSort(arr, size);

        return 0;
    }
