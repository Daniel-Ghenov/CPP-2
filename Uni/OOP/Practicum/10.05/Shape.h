#pragma once
#include <iostream>
#include <cmath>

struct Point{
    double x;
    double y;
};

double getDist(const Point& p1, const Point& p2);

class Shape{
private:
    Point* points = nullptr;
    size_t count = 0;

public:

    Shape(size_t count);
    virtual ~Shape();
    Shape(const Shape& other);
    Shape(Shape&& other);
    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other);

    void setPoint(size_t index, double x, double y);
    const Point& getPoint(size_t index) const;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual bool isIn(const Point& point) const = 0;

private:
    void copyFrom(const Shape& other);
    void free();
    void move(Shape&& other);
};