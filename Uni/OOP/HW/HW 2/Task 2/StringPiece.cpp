#include "String Piece.h"


StringPiece::StringPiece(){
    content[0] = '\0';

}

StringPiece::StringPiece(const char* content){
    strcopy_s(this->content, MAX_PIECE_LEN, content);
    size = strleng(content);
}


StringPiece& StringPiece::operator<<(const char* StringPiece){
    strconcat_s(this->content, MAX_PIECE_LEN ,StringPiece);    //Inserting after '\0'
    size += strleng(StringPiece);
    if(size > MAX_PIECE_LEN)
        size = MAX_PIECE_LEN;

    return *this;
}


void StringPiece::setContent(const char* content){
    strcopy_s(this->content, MAX_PIECE_LEN, content);
    
    size = strleng(content);

}

const char* StringPiece::getContent()const{
    return content;

}

void StringPiece::removeFirst(size_t count){
    if(count >= size){
        size = 0;
        content[size] = '\0';
        return;
    }

    for(size_t i {0} ; i <= size - count; i++){
        content[i] = content[i + count];        //taking the content back "count" places
    }
    content[size - count] = '\0';

}
void StringPiece::removeLast(size_t count){
    if(count >= size){
        size = 0;
        content[size] = '\0';
        return;
    }
    size -= count;
    content[size] = '\0';   //just making the size smaller
}

void StringPiece::remove(size_t index){
    if(index >= size){
        throw std::out_of_range("Out of Range");    
    }

    for(size_t i = index; i < size ;i++){
        content[i] = content[i + 1];    //taking the content after index back one place then making the string smaller
    } 
    content[--size] = '\0';

}
size_t StringPiece::getSize() const{
    return size;
}

const char* operator>>(const char* content, StringPiece& piece){
    char* newContent = new char[MAX_PIECE_LEN];

    strcopy_s(newContent, MAX_PIECE_LEN, content);  //Creating a new char array then concatenate new content then our content
    strconcat_s(newContent, MAX_PIECE_LEN, piece.getContent());
    piece.setContent(newContent);

    delete[] newContent;
    return piece.getContent();
}


const char* operator>>(int content, StringPiece& piece){
    char* newContent = new char[MAX_PIECE_LEN];
    char* intStr = intToStr(content);

    strcopy_s(newContent, MAX_PIECE_LEN, intStr);   //using int to String conversion
    strconcat_s(newContent,  MAX_PIECE_LEN, piece.getContent());
    piece.setContent(newContent);

    delete[] newContent;
    delete[] intStr;
    return piece.getContent();

}

void Swap(StringPiece& piece1, StringPiece& piece2){
    StringPiece temp = piece1;
    piece1 = piece2;
    piece2 = temp;
}
