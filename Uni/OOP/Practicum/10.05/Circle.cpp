#include "10.05\Circle.h"


Circle::Circle(double x, double y, double radius): Shape(1), radius(radius){}


double Circle::area() const{
    return PI * radius * radius;
}
double Circle::perimeter() const{
    return 2 * PI * radius;
}
bool Circle::isIn(const Point& point) const{
    return getDist(getPoint(0), point) < radius;
}

double Circle::getRadius() const{
    return radius;
}
void Circle::setRadius(double radius){
    this->radius = radius;
}