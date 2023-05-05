#pragma once
#include "Const.h"
#include "Helper.h"

class StringPiece{
private:
    char content[MAX_PIECE_LEN];
    size_t size = 0;
public:
    StringPiece();
    StringPiece(const char* content);


    StringPiece& operator<<(const char* StringPiece);

    void setContent(const char* content);
    const char* getContent()const;

    void removeFirst(size_t count);
    void removeLast(size_t count);
    void remove(size_t index);

    size_t getSize() const;
};

const char* operator>>(const char* content, StringPiece& piece);
const char* operator>>(int content, StringPiece& piece);
void Swap(StringPiece& piece1, StringPiece& piece2);