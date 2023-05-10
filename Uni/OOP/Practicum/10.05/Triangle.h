#include "10.05\Shape.h"

class Triangle : public Shape{

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

        
    double area() const override;
    double perimeter() const override;
    bool isIn(const Point& point) const override;

    bool operator<=>(int x);
};