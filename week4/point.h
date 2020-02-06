#ifndef __POINT_H__
#define __POINT_H__

#include <ostream>

class Point {
    public:
        /* Constructors */
        Point(): _x(0),_y(0) { }  // Default constructor (0,0)
        Point(double x,double y) : _x(x), _y(y) { } // Overloaded constructor

        /* Mutators */
        void set_x(double x) { this->_x = x; }
        void set_y(double y) { this->_y = y; }
        void move(double dx,double dy);

        /* Accessors */
        const double get_x() const { return this->_x; }
        const double get_y() const { return this->_y; }

        /* Operators */
        double operator*(const Point &) const;
        const Point operator*(int) const;
        const Point operator+(const Point&) const;
        const Point operator-(const Point&) const;
        const Point operator-() const;
        bool operator>(const Point&) const;
        bool operator<(const Point&) const;
        bool operator==(const Point&) const;

        void display() const;
        friend std::ostream& operator<<(std::ostream&,const Point&);
    private: 
        double _x = 0.0;
        double _y = 0.0;
};

#endif // __POINT_H__
