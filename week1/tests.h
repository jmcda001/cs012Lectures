#include <vector>
#include <iostream>
// Assert library allows us to check the result and provide additional information if it fails
#include <assert.h>
void test_find_min_location();
void test_find_min_location_from_start_index();
void test_selection_sort();
void display(const vector<int>& v) {
    for (unsigned i = 0;i < v.size();i++) {
        std::cout << v.at(i) << ' ';
    }
}

void run_tests() {
    std::cout << "Testing 'find_min_location' function..." << std::endl;
    test_find_min_location(); cout << endl;
    std::cout << "Testing 'find_min_location_from_start_index' function..." << std::endl;
    test_find_min_location_from_start_index(); cout << endl;
    std::cout << "Testing 'selection_sort' function..." << std::endl;
    test_selection_sort(); cout << endl;
}
void test_find_min_location() {
    int failed_tests = 0;
    int test_number = 0;
    // Test random vector (not super helpful) It's better to use deterministic tests

    // Test deterministic vector
    test_number++;
    std::vector<int> test_input = {8,3,5,2,1,6,7};
    std::cout << "Test " << test_number << ": Vector {";
    display(test_input);
    std::cout << "}...";
    int expected = 4;
    if (find_min_location(test_input) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test empty vector
    test_number++;
    std::cout << "Test " << test_number << ": Empty vector...";
    test_input.clear();
    expected = -1;
    if (find_min_location(test_input) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    // Test sorted
    test_number++;
    std::cout << "Test " << test_number << ": Sorted vector...";
    test_input.clear();
    for (unsigned i = 0; i < 10;i++) {
        test_input.push_back(i);
    }
    expected = 0;
    if (find_min_location(test_input) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test reverse sorted
    test_number++;
    std::cout << "Test " << test_number << ": Reverse sorted vector...";
    test_input.clear();
    for (unsigned i = 10; i > 0;i--) {
        test_input.push_back(i);
    }
    expected = 9;
    if (find_min_location(test_input) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test duplicates
    test_number++;
    test_input.clear();
    test_input = {8,1,5,2,1,6,7};
    std::cout << "Test " << test_number << ": Vector {";
    display(test_input);
    std::cout << "}...";
    expected = 1;
    int result = find_min_location(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    std::cout << "Passed " << test_number - failed_tests << "/" << test_number << endl;
}

void test_find_min_location_from_start_index() {
    int failed_tests = 0;
    int test_number = 0;
    // Test random vector (not super helpful)

    // Test deterministic vector
    test_number++;
    std::vector<int> test_input = {8,0,5,2,1,6,7};
    std::cout << "Test " << test_number << ": Vector {";
    display(test_input);
    std::cout << "}...";
    int start_index = 2;
    int expected = 4;
    if (find_min_location(test_input,start_index) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test empty vector
    test_number++;
    test_input.clear();
    std::cout << "Test " << test_number << ": Empty vector...";
    start_index = 2; // Value shouldn't matter
    expected = -1;
    if (find_min_location(test_input,start_index) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test sorted
    test_number++;
    std::cout << "Test " << test_number << ": Sorted vector...";
    test_input.clear();
    for (unsigned i = 0; i < 10;i++) {
        test_input.push_back(i);
    }
    start_index = 3;
    expected = start_index;
    if (find_min_location(test_input,start_index) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }


    // Test duplicates
    test_number++;
    test_input.clear();
    test_input = {8,1,5,2,1,6,7};
    std::cout << "Test " << test_number << ": Vector {";
    display(test_input);
    std::cout << "}...";
    start_index = 2;
    expected = 4;
    if (find_min_location(test_input,start_index) == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << test_number - failed_tests << "/" << test_number << endl;
}

void test_selection_sort() {
    int failed_tests = 0;
    int test_number = 0;

    // Test deterministic vector
    test_number++;
    std::vector<int> test_input = {8,0,5,2,1,6,7};
    std::cout << "Test " << test_number << ": Vector {";
    display(test_input);
    std::cout << "}...";
    vector<int> expected = {0,1,2,5,6,7,8};
    selection_sort(test_input);
    if (test_input == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test empty vector
    test_number++;
    std::cout << "Test " << test_number << ": Empty vector...";
    test_input.clear();
    expected.clear();
    selection_sort(test_input);
    if (test_input == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test sorted
    test_number++;
    std::cout << "Test " << test_number << ": Sorted vector...";
    test_input.clear();
    expected.clear();
    for (unsigned i = 0; i < 10;i++) {
        test_input.push_back(i);
        expected.push_back(i);
    }
    selection_sort(test_input);
    if (test_input == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test reverse sorted
    test_number++;
    std::cout << "Test " << test_number << ": Reverse sorted vector...";
    test_input.clear();
    expected.clear();
    for (unsigned i = 1; i < 10;i++) {
        expected.push_back(i);
    }
    for (unsigned i = 9; i > 0;i--) {
        test_input.push_back(i);
    }
    selection_sort(test_input);
    if (test_input == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test duplicates
    test_number++;
    test_input.clear();
    test_input = {8,1,5,2,1,6,7};
    std::cout << "Test " << test_number << ": Vector {";
    display(test_input);
    std::cout << "}...";
    expected.clear();
    expected = {1,1,2,5,6,7,8};
    selection_sort(test_input);
    if (test_input == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    std::cout << "Passed " << test_number - failed_tests << "/" << test_number << endl;
}

