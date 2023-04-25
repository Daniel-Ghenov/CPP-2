#include <iostream>

void fillField(char field[][3]){

    for(size_t i {0}; i < 3;i++){
        for(int j {0}; j < 3;j++){
            field[i][j] = ' ';
        }
    }
    return;
}
bool checkWin(char field[][3]) {
    
    for(size_t i {0}; i < 3;i++){
        if(field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][1] != ' ')
            return true;
        if(field[0][i] == field[1][i]  && field[1][i] == field[2][i] && field[1][i] != ' ')
            return true;
    }
    if(field[0][0] == field[1][1] && field[1][1] == field[2][2]  && field[1][1] != ' ')
        return true;
    if (field[0][2] == field[1][1] && field[1][1] == field[2][0]  && field[1][1] != ' ')
        return true;
    return false;
}
bool fullField(char field[][3]){
    for(size_t i {0}; i < 3;i++){
        for(size_t j {0}; j < 3;j++){
            if(field[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void drawField(char field[][3]){
    int const LeftAlignment = 30;

    for(size_t i {0};i < LeftAlignment;i++)
        std::cout<<" ";
    for(size_t i {1}; i <= 3;i++){
        std::cout<<"   "<<i;
    }
    std::cout<<std::endl;
    for(size_t i {0}; i < 5;i++){
        for(size_t j {0};j < LeftAlignment;j++)
            std::cout<<" ";
        if(i % 2 == 0){
            std::cout<<((i/2)+1)<<" ";
            for(int j {0};j < 3;j++){

                std::cout<<' '<<field[(i/2)][j]<<' '<<'|';
            }
        }
        else{
            std::cout<<"  ---+---+---+";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return;
}
void getInput(char field[][3], char turn){
    int moveRow = 0, moveColumn = 0;
    while(true){
        std::cin>>moveRow>>moveColumn;
        if(moveRow > 0 && moveRow < 4 && moveColumn > 0 && moveColumn < 4 && field[moveRow - 1][moveColumn - 1] == ' '){
            field[moveRow - 1][moveColumn - 1] = turn;
            return;
        }
        else    
            std::cout<<"Incorrect input Try again: ";
    }

}

int main(){

    int moveRow = 0, moveColumn = 0;
    char turn = 'O';

    char field[3][3];

    fillField(field);
    for(size_t i {0};;i++){
        drawField(field);
        if(i % 2 == 0)
            turn = 'O';
        else 
            turn = 'X';
        std::cout<<std::endl<<"It's "<<turn<<"'s turn, type in the 1-indexed coordinates of your move: ";
        getInput(field, turn);
        if(checkWin(field)){
            std::cout<<turn<<" won! Congratulations!";
            return 0;
        }
        if(fullField(field)){
            std::cout<<"It's a draw!!";
            return 0;
        }
    }
    
    return 0;

}