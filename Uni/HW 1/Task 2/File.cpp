#include "File.h"

File::File() {}


File::File(const char* name, size_t createDay, size_t createMonth, size_t createYear,
    size_t creatHours, size_t createMins, size_t createSeconds, const char* permissions): 
    createTime (createDay, createMonth, createYear,creatHours, createMins, createSeconds)
    , permissions(permissions){

    strcpy(this->name, name);
    editTime = createTime;
}

void File::setName(const char* name){
    strcpy(this->name, name);
}
void File::setContent(const char* content){
    strcpy(this->content, content);
    setSize();
}
void File::setSize(){
    this->size = strlen(content);
}
const char* File::getName() const {
    return this->name;
}
const char* File::getContent() const {
    return this->content;
}
const char* File::getPermissions() const {
    return permissions.getPermissions();
}
size_t File::getSize() const {
    return this->size;
}
bool File::getPermission(char group , char right) const{
    return permissions.getPermission(group, right);
}
const CompleteDate& File::getCreate() const{
    return createTime;
}
const CompleteDate& File::getEdit() const{
    return editTime;
}
void File::setPermission(char group, char right, bool set){
    permissions.setPermission(group, right, set);
}
void File::printContent(char user) const{
    if(permissions.getPermission(user, 'r'))
        std::cout<<content<<std::endl;
}
void File::printInfo() const{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Size: "<<size<<std::endl;
    std::cout<<"Created on: ";
    createTime.printDate();
    std::cout<<"Last edited on: ";
    editTime.printDate();
    std::cout<<"Rights: ";
    permissions.print();
}
void File::addContent(const char* content){
    int leftSpace = MAX_CONTENT_LEN - size;
    strcpy_s(this->content + size, leftSpace, content);
    setSize();
}
void File::setEdit(size_t editDay, size_t editMonth, size_t editYear,
            size_t editHours, size_t editMins, size_t editSeconds){
    editTime.setDate(editDay, editMonth, editYear,editHours, editMins, editSeconds);
}
void File::deleteFile(){
    setContent("");
    setName("");
    permissions.setPermissions("---------");
    createTime.setDate(1,1,1,0,0,0);
    editTime.setDate(1,1,1,0,0,0);
}