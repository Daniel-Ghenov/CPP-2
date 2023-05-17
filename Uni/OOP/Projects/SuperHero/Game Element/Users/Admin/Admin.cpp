#include "Admin.h"

Admin::Admin(const String& firstName, const String& lastName, const String& email, const char* username, const String& password):
            User(firstName, lastName, email, username, password){

}

void Admin::print() const{
    std::cout<<"First name: "<<firstName()<<std::endl;
    std::cout<<"Last name: "<<lastName()<<std::endl;
    std::cout<<"username: "<<username()<<std::endl;
    std::cout<<"email: "<<email()<<std::endl;

}
void Admin::adminPrint() const{
    print();
}

