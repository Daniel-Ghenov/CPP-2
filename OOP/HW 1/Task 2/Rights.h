#pragma once
#include "Const.h"
#include <iostream>
#include <string.h>

struct Rights{
private:
    char rights[RIGHTS_NUM];
    
    bool isValidRights(const char* rights);
public:
    Rights();
    Rights(const char*);
    bool hasRead() const;
    bool hasWrite() const; 
    bool hasExec() const;  
    bool hasRight(char right) const;
    void setRight(char right, bool set);
    void setRead(bool set);
    void setWrite(bool set); 
    void setExec(bool set);
    void setRights(const char* rights);
    const char* getRights() const;
};