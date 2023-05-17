#include "ControlTypes.h"

Label::Label(const String& data, const String& name, size_t size, size_t location): _data(data), Controll(name, size, location) {}


void Label::setDataDialog(){
    
    std::cout<<"Enter text for your label"<<std::endl;
    std::cin>>_data;
}


CheckBox::CheckBox(bool checked, const String& name, size_t size, size_t location): isChecked(checked), Controll(name, size, location){
    
}
void CheckBox::setDataDialog(){
    std::cout<<"Enter 1 for on and 0 for off"<<std::endl;
    std::cin>>isChecked;
}