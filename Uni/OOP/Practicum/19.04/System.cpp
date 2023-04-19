#include "System.h"


System::System(){
    messages = new Message[2];
    msgCap = 2;
}

System::~System(){
    free();
}

System::System(const System& other){
    copyFrom(other);
}

System& System::operator=(const System& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}


bool System::addUser(const User& user){
    if(userSize == MAX_USER_COUNT)
        return false;

    users[userSize++] = user;
    return true;
}

void System::sendMessage(const User& sender, const String& message, const User& reciever){
    if(msgSize == msgCap){
        resize(2 * msgCap);
    }
    messages[msgSize].Message = message;
    messages[msgSize].sender = &sender;
    messages[msgSize++].reciever = &reciever;
}

Message* System::readMessage(const User& sender, const User& receiever){

    Message* commonMsg = new Message[msgSize];
    size_t commonMsgCounter = 0;

    for(size_t i {0}; i < msgSize; i++){
        if(messages[i].reciever == &receiever && messages[i].sender == &sender){
            commonMsg[commonMsgCounter++] = messages[i];
        }
    }
    return commonMsg;
}


void System::free(){
    delete[] messages;
    messages = nullptr;
    msgSize = msgCap = 0;
}

void System::copyFrom(const System & other){
    msgSize = other.msgSize;
    msgCap = other.msgCap;

    messages = new Message[msgCap];

    for(size_t i {0}; i < msgSize; i++){
        messages[i] = other.messages[i];
    }
    
}
void System::resize(size_t newSize){
    msgSize = (newSize > msgSize)? msgSize : newSize;
    msgCap = newSize;
    Message* newMsg = new Message[msgSize];

    for(size_t i {0}; i < msgSize; i++){
        newMsg[i] = messages[i];
    }
    delete[] messages;
    messages = newMsg;
}
