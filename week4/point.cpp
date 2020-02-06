#include "point.h"
#include <iostream>

using namespace std;

void Point::display() const {
    cout << '(' << _x << ',' << _y << ')';
}

void Point::move(double dx,double dy) {
    this->_x += dx;
    this->_y += dy;
}

ostream& operator<<(ostream& out,const Point& rhs) {
    out << '(' << rhs._x << ',' << rhs._y << ')';
    return out;
}

// Scalar multiplication
double Point::operator*(const Point &rhs) const {
    return (this->_x * rhs._x) + (this->_y * rhs._y);
}
// Dot product
const Point Point::operator*(int scale) const {
    return Point(this->_x * scale,this->_y * scale);
}
const Point Point::operator+(const Point& rhs) const {
    return Point(this->_x + rhs._x,this->_y + rhs._y);
}

const Point Point::operator-() const {
    return Point(-this->_x,-this->_y);
}

const Point Point::operator-(const Point& rhs) const {
    return Point(this->_x - rhs._x,this->_y - rhs._y);
}

bool Point::operator==(const Point& rhs) const {
    return this->_x == rhs._x && this->_y == rhs._y;
}

