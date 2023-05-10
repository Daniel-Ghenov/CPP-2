#include "10.05\Shape.h"

class Circle : public Shape{
private:
    double radius = 0;

public:
    Circle(double x, double y, double radius);

    double area() const override;
    double perimeter() const override;
    bool isIn(const Point& point) const override;

    double getRadius() const;
    void setRadius(double radius);

    const static double PI = 3.14159; 
};