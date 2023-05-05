#include "System.h"

void System::free(){
    delete[] files;
    files = nullptr;
}
void System::copyFrom(const System& other){
    files = new File[other.maxSize];
    for(size_t i {0}; i < other.currSize;i++){
        files[i] = other.files[i];
    }
    maxSize = other.maxSize;
    currSize = other.currSize;
}

System::System(size_t size){
    if(size == 0)
        return;
    maxSize = size;

    File* files = new File[maxSize];
    this->files = files;
}
System::~System(){

    free();
}
int System::findName(const char* name) const{

    for(size_t i {0}; i < currSize; i++){
        if(strcmp(name, files[i].getName()) == 0)
            return i;
    }
    std::cout<<"Error file not found"<<std::endl;
    return -1;
}
void System::addFile(const char* name, unsigned createDay, unsigned createMonth, unsigned createYear,
    unsigned creatHours, unsigned createMins, unsigned createSeconds, const char* permissions){

    if(currSize == maxSize)
        return;
    files[currSize++] = File(name, createDay, createMonth, createYear,
                    creatHours, createMins, createSeconds, permissions);

}
void System::editFile(const char* name, const char* content, unsigned editDay, unsigned editMonth, unsigned editYear,
                    unsigned editHours, unsigned editMins, unsigned editSeconds, char user){

    int file = findName(name);
    if(file == -1 || !files[file].getPermission(user, 'w')){
        std::cout<<"Error"<<std::endl;
        return;
    }
    files[file].setContent(content);
    files[file].setEdit(editDay, editMonth, editYear, editHours, editMins, editSeconds);
}
void System::addInFile(const char* name, const char* content, unsigned editDay, unsigned editMonth, unsigned editYear,
                    unsigned editHours, unsigned editMins, unsigned editSeconds, char user){
    
    int file = findName(name);
    if(file == -1 || !files[file].getPermission(user, 'w')){
        std::cout<<"Error"<<std::endl;
        return;
    }
    files[file].addContent(content);    //we add content then set the edit time
    files[file].setEdit(editDay, editMonth, editYear, editHours, editMins, editSeconds);
}
void System::deleteFile(const char* name, char user){   

    int file = findName(name);
    if(file == -1 || !files[file].getPermission(user, 'x')) //deleting requires executing rights
        return;

    std::swap(files[file], files[--currSize]);
    files[currSize].deleteFile();
}
void System::editRights(const char* name, char group, char right){  //set a permission for a file 

    int file = findName(name);
    if(file == -1)
        return;
    files[file].setPermission(group, right, !files[file].getPermission(group, right));
}
void System::printContent(const char* name, char group){    //prints the contents of a file

    int file = findName(name);
    if(file == -1)
        return;
    files[file].printContent(group);
}
void System::printInfo(const char* name){   //print all info from a file

    int file = findName(name);
    if(file == -1)
        return;
    files[file].printInfo();
}
void System::print(){

    for(size_t i {0}; i < currSize; i++){
        std::cout<<files[i].getName()<<std::endl;
    }
}
shouldSwap System::returnSortFunc(SortOptions option){

    switch (option)
    {
    case SortOptions::name :        //a function which takes our enum class and returns a function pointer
        return Sort::sortByName;   //so we can determine which function to use to sort
    case SortOptions::creationTime :
        return Sort::sortByCreate;
    case SortOptions::editTime : 
        return Sort::sortByEdit;
    case SortOptions::size : 
        return Sort::sortBySize;
    default:
        return nullptr;
    }
}
void System::sort(SortOptions sort){
    
    int maxIdx = 0;
    shouldSwap func = returnSortFunc(sort); //setting the sorting function

    if(func == nullptr)
        return;

    for(size_t i {0}; i < currSize; i++){
        for(size_t j = i; j < currSize; j++){
            if(func(files[maxIdx], files[j])){
                maxIdx = j;
            }
        }
        std::swap(files[maxIdx], files[i]);
        maxIdx = i + 1;
    }
}

System::System(const System& other) {   //Copy Constructor
   copyFrom(other);
}

System& System::operator=(const System& other){ //Operator '='
   if(this == &other)
       return *this;
   free();
   copyFrom(other);
   return *this;
}