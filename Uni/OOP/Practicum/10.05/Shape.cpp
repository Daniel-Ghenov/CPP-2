#include "10.05\Shape.h"

double getDist(const Point& p1, const Point& p2){
    return sqrt((p1.x - p2.x) * (p1.x * p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}


Shape::Shape(size_t count){
    points = new Point[count];
    this->count = count;
}

Shape::~Shape(){
    free();
}

Shape::Shape(const Shape& other){
    copyFrom(other);
}

Shape::Shape(Shape&& other){
    move(std::move(other));
    
}

Shape& Shape::operator=(const Shape& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Shape& Shape::operator=(Shape&& other){
        if(this != &other){
        free();
        move(std::move(other));
    }
    return *this;
}

void Shape::setPoint(size_t index, double x, double y){
    points[index].x = x;
    points[index].y = y;
}
const Point& Shape::getPoint(size_t index) const{
    return points[index];
}

void Shape::copyFrom(const Shape& other){
    points = new Point[other.count];
    for(size_t i {0}; i < other.count; i++){
        points[i] = other.points[i];
    }
    count = other.count;
}
void Shape::free(){
    delete[] points;
    points = nullptr;
    count = 0;
}
void Shape::move(Shape&& other){
    points = other.points;
    other.points = nullptr;
    count = other.count;
    other.count = 0;
}