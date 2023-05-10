#include "10.05\Shape.h"

class Rectangle : public Shape{

    Rectangle(int x1, int y1, int x2, int y2);

    double area() const override;
    double perimeter() const override;
    bool isIn(const Point& point) const override;
};