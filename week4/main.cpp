#include <iostream>
#include "point.h"
#include "point_test.h"

using namespace std;

int main() {
    run_tests();

    return 0;

    Point p1;
    cout << p1;
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

