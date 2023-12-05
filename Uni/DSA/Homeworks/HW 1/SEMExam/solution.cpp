#include <vector>
#include <iostream>
#include <algorithm>

const int ENGLISH_ALPHABET_COUNT = 26;

void failedLetters(int numStudents, int minFailed, std::string& results){
    std::vector<int> failedCounts(ENGLISH_ALPHABET_COUNT, 0);

    for(auto it = results.begin(); it != results.end(); it++){
        if(*it <= 'Z' && *it >= 'A'){
            failedCounts[*it - 'A']++;
        }
    }

    for(int i = 0; i < ENGLISH_ALPHABET_COUNT; i++){
        if(failedCounts[i] >= minFailed){
            std::cout<< char(i + 'A');
        }
    }
}


int main() {
    int numExams, numStudents, minFailed;
    std::string results;
    std::cin>>numExams;
    for(int i = 0; i < numExams; i++){
        std::cin>>numStudents>>minFailed>>results;
        failedLetters(numStudents, minFailed, results);
        std::cout<<std::endl;
    }

    return 0;
}
