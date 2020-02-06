#include "point.h"
#include <iostream>

void test_constructors();
void test_mutators();
void test_operators();
void test_move();

void run_tests() {
    test_constructors();
    std::cout << std::endl;
    test_mutators();
    std::cout << std::endl;
    test_operators();
    std::cout << std::endl;
    test_move();
    std::cout << std::endl;
}

void test_move() {
    std::cout << "Testing move..." << std::endl;
    int failed_tests = 0;
    int test_number = 0;

    // Test addition
    test_number++;
    double test_x = 2.5, test_y = 3.1;
    double test_dx = 5.7, test_dy = 1;
    Point test_p1 = Point(test_x,test_y);
    std::cout << "Test " << test_number << ": move " << test_p1 << " by (" 
        << test_dx << ',' << test_dy  << ")...";
    Point expected = Point(8.2,4.1);
    test_p1.move(test_dx,test_dy);
    if (expected == test_p1) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << std::endl;
}

void test_operators() {
    std::cout << "Testing operators..." << std::endl;
    int failed_tests = 0;
    int test_number = 0;

    // Test addition
    test_number++;
    double test_x1 = 2.5, test_y1 = 3.1;
    double test_x2 = 5.7, test_y2 = 1;
    Point test_p1 = Point(test_x1,test_y1);
    Point test_p2 = Point(test_x2,test_y2);
    std::cout << "Test " << test_number << ": addtion " << test_p1 << "+" <<  test_p2 << "...";
    Point expected = Point(8.2,4.1);
    Point result = test_p1 + test_p2;
    if (expected == result) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test addition
    test_number++;
    test_x1 = 5.2; test_y1 = 3.1;
    test_x2 = -2.2; test_y2 = -1;
    test_p1 = Point(test_x1,test_y1);
    test_p2 = Point(test_x2,test_y2);
    std::cout << "Test " << test_number << ": addtion " << test_p1 << "+" <<  test_p2 << "...";
    expected = Point(3,2.1);
    result = test_p1 + test_p2;
    if (expected == result) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test subtraction
    test_number++;
    test_x1 = 5.2; test_y1 = 3.1;
    test_x2 = 2.2; test_y2 = 1;
    test_p1 = Point(test_x1,test_y1);
    test_p2 = Point(test_x2,test_y2);
    std::cout << "Test " << test_number << ": subtraction " << test_p1 << "-" <<  test_p2 << "...";
    expected = Point(3,2.1);
    result = test_p1 - test_p2;
    if (expected == result) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test scalar multiplication
    test_number++;
    test_x1 = 5.2; test_y1 = 3.1;
    double test_scalar = 4;
    test_p1 = Point(test_x1,test_y1);
    std::cout << "Test " << test_number << ": scalar multiplication " 
        << test_p1 << "*" <<  test_scalar << "...";
    expected = Point(5.2*4,3.1*4);
    result = test_p1 * test_scalar;
    if (expected == result) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test dot product
    test_number++;
    test_x1 = 2.2; test_y1 = 1.3;
    test_x2 = 1; test_y2 = 3;
    test_p1 = Point(test_x1,test_y1);
    test_p2 = Point(test_x2,test_y2);
    std::cout << "Test " << test_number << ": dot product " 
        << test_p1 << "*" <<  test_p2 << "...";
    double expected_scalar = 6.1;
    double scalar_result = test_p1 * test_p2;
    if (expected == result) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test dot product
    test_number++;
    test_x1 = 2.2; test_y1 = 1.3;
    test_p1 = Point(test_x1,test_y1);
    std::cout << "Test " << test_number << ": negation (-p1)" << "...";
    expected = Point(-test_x1,-test_y1);
    result = -test_p1;
    if (expected == result) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << std::endl;
}

void test_constructors() {
    std::cout << "Testing constructors..." << std::endl;
    int failed_tests = 0;
    int test_number = 0;

    // Test set_x
    test_number++;
    Point test_input = Point();
    double test_x = 2.5;
    test_input.set_x(test_x);
    std::cout << "Test " << test_number << ": test default constructor and accessors...";
    if (test_input.get_x() == test_x && test_input.get_y() == 0.0) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test set_y
    test_number++;
    test_input = Point();
    double test_y = 3.2;
    test_input.set_y(test_y);
    std::cout << "Test " << test_number << ": test default constructor and accessors...";
    if (test_input.get_x() == 0.0 && test_input.get_y() == test_y) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << std::endl;
}

void test_mutators() {
    std::cout << "Testing mutators..." << std::endl;
    int failed_tests = 0;
    int test_number = 0;

    // Test constructor()/accessors
    test_number++;
    Point test_input = Point();
    std::cout << "Test " << test_number << ": test default constructor and accessors...";
    if (test_input.get_x() == 0.0 && test_input.get_y() == 0.0) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test constructor(double,double)
    test_number++;
    double test_x = 2.5;
    double test_y = 3.2;
    test_input = Point(test_x,test_y);
    std::cout << "Test " << test_number << ": test default constructor and accessors...";
    if (test_input.get_x() == test_x && test_input.get_y() == test_y) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << std::endl;
}
