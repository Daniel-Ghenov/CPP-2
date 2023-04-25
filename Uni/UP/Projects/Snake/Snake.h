#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <time.h>

const int fieldRows = 10;
const int fieldColumns = 10;

class Snake {
        public: 
        void getInput(char& direction){
        
        HANDLE hstdin;
        DWORD mode;

        hstdin = GetStdHandle ( STD_INPUT_HANDLE );
        GetConsoleMode(hstdin, &mode);
        SetConsoleMode(hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);

        char a = std::cin.get();

        SetConsoleMode(hstdin, mode);
        if(a == 'a' || a == 's' || a == 'w' || a == 'd')
            direction = a;
    }

    bool snakeIsInPos( std::vector<std::vector<int>>& snake, int row, int column){

        std::vector<int> temp {row, column};
        std::vector<std::vector<int>>::iterator it;

        it = std::find(snake.begin(), snake.end(), temp);

        if(it == snake.end())
            return false;
        return true;
    }

    void fillField(std::vector<std::vector<char>>& field){
        for(size_t i {0}; i < field.size(); i++){
            for(size_t j {0}; j < field.size();j++){
                if(i == 0)
                    field[i][j] = '_';
                else if(j == 0)
                    field[i][j] = '|';
                else if(j == field.size() - 1)
                    field[i][j] = '|';
                else if(i == field.size() - 1)
                    field[i][j] = '_';
            }
        }
    }

    void drawField(std::vector<std::vector<char>>& field, std::vector<std::vector<int>>& snake, std::vector<int>& head){
        for(size_t i {0}; i < field[0].size(); i++){
            for(size_t j {0}; j < field.size();j++){
                if(i == head[0] && j == head[1])
                    std::cout<<'H';
                else if(snakeIsInPos(snake, i, j))
                    std::cout<<'*';
                else 
                    std::cout<<field[i][j];

                if(i != 0 && i != field[0].size() - 1 && j < field.size() - 2 && j != 0)
                    std::cout<<"  ";
                else if(j < field.size() - 2 && j!= 0)
                    std::cout<<"__";
            }
            std::cout<<std::endl;
        }


    }
    bool isFruit(std::vector<std::vector<char>>& field){
        std::vector<std::vector<char>>::iterator row;
        for(row = field.begin(); row!= field.end(); row++){
            if((std::find(row->begin(), row->end(), 'A')) != row->end())
                return true;
        }
        return false;
    }

    void changeSnake(std::vector<std::vector<char>>& field, std::vector<std::vector<int>>& snake, std::vector<int>& head, char direction, bool& gameLost){
        bool ateApple = false;

        switch(direction){
            case 'a': head[1]--;
            break;
            case 'w': head[0]--;
            break;
            case 's': head[0]++;
            break;
            case 'd': head[1]++;
            break;
        }
        if(field[head[0]][head[1]] == '|' || field[head[0]][head[1]] == '_' || snakeIsInPos(snake, head[0], head[1])){
            std::cout<<"\nYou Lose. \n";
            gameLost = true;
            return;
        }
        if(field[head[0]][head[1]] == 'A'){
            ateApple = true;
            field[head[0]][head[1]] = ' ';
        }

        snake.insert(snake.begin(), {head[0], head[1]});
        if(!ateApple)
            snake.pop_back();
        return;
    }
    void generateFruit(std::vector<std::vector<char>>& field, std::vector<std::vector<int>>& snake){
        int appleRow = (rand() % (fieldRows - 2)) + 1, appleColumn = (rand() % (fieldColumns - 2)) + 1;
        while(snakeIsInPos(snake, appleRow, appleColumn)){
            appleRow = (rand() % (fieldRows - 2)) + 1, appleColumn = (rand() % (fieldColumns - 2)) + 1;
        }
        field[appleRow][appleColumn] = 'A';
    }

    void playGame(std::vector<std::vector<char>>& field, std::vector<std::vector<int>>& snake, std::vector<int>& head, char& direction){
        bool gameLost = false;
        if(!isFruit(field)){
            generateFruit(field, snake);
        }
        drawField(field, snake, head);
        getInput(direction);
        changeSnake(field, snake, head, direction, gameLost);

        if(gameLost)
            return;
        playGame(field, snake, head, direction);

    }

};