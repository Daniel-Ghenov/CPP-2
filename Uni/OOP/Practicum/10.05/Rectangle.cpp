#include "10.05\Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2): Shape(4){
    setPoint(0, x1, y1);
    setPoint(1, x1, y2);
    setPoint(2, x2, y2);
    setPoint(3, x2, y1);
}

double Rectangle::area() const{
    return (getDist(getPoint(0), getPoint(1)) * getDist(getPoint(1), getPoint(2)));
}
double Rectangle::perimeter() const{
    return 2 * (getDist(getPoint(0), getPoint(1)) + getDist(getPoint(1), getPoint(2)));

}
bool Rectangle::isIn(const Point& point) const{
    return(point.x < getPoint(0).x && point.x > getPoint(2).x && point.y < getPoint(2).y && point.y > getPoint(0).y);
}
