#include <iostream>

using namespace std;

// Show the difference between struct and class (default behavior is private in class, struct is public)
class Point {
    public:
        Point();  // Special function called 'constructor'
        Point(double,double); // Overloaded constructor
        void set_x(double);
        void set_y(double);
        void display() const;
    private: // Add this after showing default private
        double x_coord = 0.0;
        double y_coord = 0.0;

};

Point::Point() {
    x_coord = y_coord = 0;
}
Point::Point(double x,double y) {
    x_coord = x;
    y_coord = y;
}

// Differentiate between explicit and implicit parameter (this)
void Point::set_x(double new_x) { // Without proper scoping then with (explain ::)
    x_coord = new_x; // How does it know about x_coord?
}
void Point::set_y(double new_y) { // Without proper scoping then with (explain ::)
    y_coord = new_y;
}

void Point::display() const { // What does this const do?
    if (x_coord == 0 && y_coord == 0) { // What happens if assignment instead of equality
        cout << "(Origin)";
    }
    cout << '(' << x_coord << ',' << y_coord << ')';
};

int main() {
    Point p1;
    //p1.x_coord = 3.1; // Compilation error for accessing private members
    p1.set_x(3.1); // Mutator method
    p1.set_y(2.7); // Mutator method
    //cout << p1.xCoord << endl;
    p1.display();
    cout << endl;

    Point p2(3.1,-2.7); // Second point constructor
    Point p3; // Doesn't work if default constructor not defined

    return 0;
}

