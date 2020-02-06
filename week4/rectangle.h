#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "point.h"

class Rectangle {
    private:
        // How do we want to store the rectangle internally?
    public:
        /* Constructors */
        Rectangle(); 
        Rectangle(const Point &ll,double w,double h);
        Rectangle(const Point &ll,const Point &ur);

        // LL: (x,y), W: w, H: h
        void display() const;

        // (x,y) (x,y)
        // (x,y) (x,y)
        void display_corners() const;

        /* Mutators */
        void move(double dx,double dy);

        void change_width(double percent);
        void change_height(double percent);

        /* Accessors */
        double width() const;
        double height() const;
        double area() const;
        double perimeter() const;

        const Point lower_left() const;
        const Point lower_right() const;
        const Point upper_left() const;
        const Point upper_right() const;
};

#endif // __RECTANGLE_H__
