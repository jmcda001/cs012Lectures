#include <iostream>

void run_tests() {
    std::cout << "Testing example..." << endl;
    test_example();
    cout << endl;
}

void test_example() {
    int failed_tests = 0;
    int test_number = 0;

    // Test description
    test_number++;
    // type test_input = initial_value;
    int test_input = 0;
    std::cout << "Test " << test_number << ": test description";
    int expected = 0;
    int result = func(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << endl;
}
