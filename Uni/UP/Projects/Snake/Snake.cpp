#include "Snake.h"

int main(){

    Snake s1;
    srand(time(NULL));
    
    std::vector<std::vector<char>> field(fieldRows, (std::vector<char>(fieldColumns, ' ')));
    std::vector<int> head (4,4);
    std::vector<std::vector<int>> snake {{head[0], head[1]}, {3,4}, {2,4}};
    char direction = 'a';
    s1.fillField(field);
    s1.playGame(field, snake, head, direction);

    std::cout<<"Good Game!! You reached a length of: "<<snake.size();
    return 0;

}