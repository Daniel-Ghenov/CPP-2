#include <iostream>
#include <cmath>
#include <cstdlib>

void fncalc(int loopgoal, double& x){
    if(x < 2022){
        if(static_cast<int>(x) % 2 == 1){
            x -= std::floor(x);
            x = std::abs(x - 1);
        }else
            x -= std::floor(x);
    }else
        x -= 2022;
}

void fncalc(int loopnum, double& x, int loopgoal){
    if(loopgoal <= loopnum)
        return;
    if(x < 1){
         loopnum++;
        x = std::abs(x - 1);
        //std::cout<<"for Loop number: "<<loopnum <<" f(x) is: "<<x<<std::endl;
        return;
    }
    loopnum++;
    x = std::abs(x - 1);
    //std::cout<<"for Loop number: "<<loopnum <<" f(x) is: "<<x<<std::endl;
    fncalc(loopnum, x, loopgoal);

}
void fnloop(int loopnum, double& x, int loopgoal, double outsideLoopNum, double outsideLoopGoal){
    if(outsideLoopGoal <= outsideLoopNum)
        return;
    outsideLoopNum = outsideLoopNum + 0.001;
    x = x = std::pow(outsideLoopNum, 2);
    fncalc(loopgoal, x);
    if(x == outsideLoopNum/22){
        std::cout<<"___________________"<<std::endl;
        std::cout<<"Found a solution at OLN: "<<outsideLoopNum<<std::endl;
        return;
    }
    fnloop(0, x, loopgoal, outsideLoopNum, outsideLoopGoal);
}



int main(){

    int loopgoal {2022};
    double x;
    fnloop(0, x, loopgoal, 0,50);

    std::cout<<"_____________________"<<std::endl;
    std::cout<<"Final answer is: "<<x<<", with a starting x of: ";

    return 0;
}