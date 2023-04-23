#pragma once
#include "Message.h"

class System{
private:
    User users[MAX_USER_COUNT];
    Message* messages = nullptr;
    size_t userSize = 0;
    size_t msgCap = 0;
    size_t msgSize = 0;

public:

    System();
    ~System();
    System(const System& other);
    System& operator=(const System& other);

    bool addUser(const User& user);
    void sendMessage(const User& sender, const String& message, const User& reciever);
    Message* readMessage(const User& sender, const User& receiever);

private:
    void free();
    void copyFrom(const System & other);
    void resize(size_t newSize);
};

