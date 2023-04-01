#include <iostream>
#include <fstream>
#include <string.h>

const int MAX_NAME_LEN = 21;
const int MAX_TASK_LEN = 51;
const int MAX_TASK_NUM = 10;
const int MAX_TITLE_LEN = 65;
const int MAX_GAME_NUM = 20;


bool isUpper(char ch){
    return ch > 'A' && ch < 'Z';
}
bool isLower(char ch){
    return ch > 'a' && ch < 'z';
}
bool isValidName(const char* name){
    if(!isUpper(name[0]))
        return false;
    while(name){
        if(!isLower(*name))
            return false;
    }
    return true;
}

class Teacher {
private:
    char name[MAX_NAME_LEN];
    int age;
    int experience;
public:
    int getAge() const;
    int getExperience() const;
    const char* getName() const;
    void setAge(int age);
    void setExperience(int experience);
    void setName(const char* name);
    explicit Teacher(int age, int experience, const char* name);
    Teacher(): Teacher(0,0,"Unknown"){}

};

int Teacher::getAge() const{
    return age;
}
int Teacher::getExperience() const{
    return experience;
}
const char* Teacher::getName() const{
    return name;
}
void Teacher::setAge(int age){
    if(age < 5 || age > 90)
        age = 5;
    this->age = age;
}
void Teacher::setExperience(int experience){
    if(experience > age - 20)
        experience = age - 20;
    this->experience = experience;
}
void Teacher::setName(const char* name){
    if(isValidName(name))
        strcpy(this->name, name);
    else
        strcpy(this->name,"Error");
}
Teacher::Teacher(int age, int experience, const char* name){
    setAge(age);
    setExperience(experience);
    setName(name);
}
class Task{
protected:
    char name[MAX_NAME_LEN];
    char task[MAX_NAME_LEN];
    unsigned points;
public:
    unsigned getPoints() const;
    const char* getName() const;
    const char* getTask() const;
    void setPoints(unsigned points);
    void setName(const char* name);
    void setTask(const char* task);
    Task(const char* name, const char* task, unsigned points);
    Task():Task("\0", "\0", 1){}
    void writeToFile(std::ofstream&) const;



};
unsigned Task::getPoints() const{
    return points;
}
const char* Task::getName() const{
    return name;
}
const char* Task::getTask() const{
    return task;
}
void Task::setPoints(unsigned points){
    if(points == 0)
        points = 1;

    this->points = points;
}
void Task::setName(const char* name){
    if(!isValidName(name))
        strcpy(name, "Error");
    strcpy(this->name, name);
}
void Task::setTask(const char* task){
    strcpy(this->task, task);
}
Task::Task(const char* name, const char* task, unsigned points){
    setName(name);
    setTask(task);
    setPoints(points);
}
void Task::writeToFile(std::ofstream& outFile){
    outFile.write((const char*)this, sizeof(this));
}
class Exam{
private:
    unsigned currSize = 0;
    Task tasks[MAX_TASK_NUM];
    unsigned pointsToPass;
public:
    void writeToFile(std::ofstream&) const;
    void readFromFile(std::ifstream&);
    void changeMin(unsigned);
    void addTask(const Task&);
    int getMax() const;
};
void Exam::readFromFile(std::ifstream& inFile){
    if(!inFile.is_open())
        return;
    inFile.read((char*) this, sizeof(this));
}
void Exam::changeMin(unsigned points){
    pointsToPass = points;
}
void Exam::writeToFile(std::ofstream& outFile) const{
    if(!outFile.is_open())
        return;
    outFile.write((const char*)this, sizeof(this));
}
void Exam::addTask(const Task& task){
    if(currSize < MAX_TASK_NUM)
        tasks[currSize++] = task;
}
int Exam::getMax() const{
    int max = 0;
    for(size_t i {0}; i < currSize; i++){
        max += tasks[i].getPoints();
    }
}

class Game{
private:
    char title[MAX_TITLE_LEN];
    bool isAvailable;
    unsigned price;

public:
    const char* getTitle() const;
    bool getAvailable() const;
    unsigned getPrice() const;
    void setTitle(const char*);
    void setAvialable(bool);
    void setPrice(unsigned);
    bool isFree() const;
    void print() const;
    Game(const char*, bool, unsigned);
    Game():Game("\0", 0. 0){}

};
const char* Game::getTitle() const{
    return title;
}
bool Game::getAvailable() const{
    return isAvailable;
}
unsigned Game::getPrice() const{
    return price;
}
void Game::setTitle(const char*){
    strcpy_s(this->title, title, MAX_TITLE_LEN);
}
void Game::setAvialable(bool available){
    isAvailable = available;
}
void Game::setPrice(unsigned price){
    this->price = price;
}
bool Game::isFree() const{
    return price == 0;
}
void Game::print() const{
    std::cout<<title<<" is: "<<(isAvailable)? "available" : "not available"<<" and costs: "<<price<<std::endl;
}
Game::Game(const char* title, bool available, unsigned price){
    setTitle(title);
    setAvialable(available);
    setPrice(price);
}
class GamePlatform{
private:
    Game games[MAX_GAME_NUM];
    size_t currSize = 0;
public:
    void addGame(const Game&);
    int getGameIdx(const Game&) const;
    void print() const;
    void mostExpensive() const;
    void leastExpensive() const;
    void printFree() const;
    void removeGame(size_t); 

};
void GamePlatform::addGame(const Game& game){
    if(currSize >= MAX_GAME_NUM)
        return;
    games[currSize++] = game;
}
int GamePlatform::getGameIdx(const Game& game) const{
    for(size_t i {0}; i < currSize; i++){
        if(games[i] == game)
            return i;
    }
    return -1;
}
void GamePlatform::print() const{
    for(size_t i{0} ; i < currSize; i++){
        gmaes[i].print();
    }
}
void GamePlatform::mostExpensive() const{
    int mostExpensive = 0;
    int iter = 0;
    for(size_t i {0}; i < currSize; i++){
        if(games[i].getPrice() > mostExpensive){
            mostExpensive = games[i].getPrice();
            iter = i;
        }
    }
    return iter;
}
void GamePlatform::leastExpensive() const{
    int leastExpensive = 0;
    int iter = 0;
    for(size_t i {0}; i < currSize; i++){
        if(games[i].getPrice() < leastExpensive){
            leastExpensive = games[i].getPrice();
            iter = i;
        }
    }
    return iter;
}
void GamePlatform::printFree() const{
    for(size_t i {0}; i < currSize; i++){
        if(games[i].isFree())
            std::cout<<i<<", ";
    }
}



int main(){

    return 0;
}