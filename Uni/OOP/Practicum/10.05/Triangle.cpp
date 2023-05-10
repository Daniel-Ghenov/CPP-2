#include "10.05\Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3): Shape(3){
    setPoint(0, x1, y1);
    setPoint(1, x2, y2);
    setPoint(0, x3, y3);
}

double Triangle::area() const{
    double sideA = getDist(getPoint(0), getPoint(1));
    double sideB = getDist(getPoint(1), getPoint(2));
    double sideC = getDist(getPoint(0), getPoint(2));

    double halfPerim = (sideA + sideB + sideC) / 2;

    return sqrt(halfPerim*(halfPerim - sideA)*(halfPerim - sideB)*(halfPerim - sideC));
}
double Triangle::perimeter() const{

    double sideA = getDist(getPoint(0), getPoint(1));
    double sideB = getDist(getPoint(1), getPoint(2));
    double sideC = getDist(getPoint(0), getPoint(2));

    sideA <=> sideB;

    return(sideA + sideB + sideC);
}
bool Triangle::isIn(const Point& point) const{

}