#include <iostream>
void test_find_min_location();
bool test_find_min_small_array();
bool test_find_min_empty_array();
bool test_find_min_sorted();
bool test_find_min_duplicates();

void test_selection_sort();
bool test_selection_sort_deterministic();
bool test_selection_sort_empty_array();
bool test_selection_sort_sorted_array();
bool test_selection_sort_reverse_sorted();
bool test_selection_sort_duplicates();

bool verify_sorted(const int arr[],unsigned int size) {
    if (size == 0) { return true; }
    for (unsigned i = 0;i < size - 1;i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

void run_tests() {
    std::cout << "Testing 'find_min_location' function..." << std::endl;
    test_find_min_location(); cout << endl;
    std::cout << "Testing 'selection_sort' function..." << std::endl;
    test_selection_sort(); cout << endl;
}

void test_find_min_location() {
    unsigned int test_number = 0;
    unsigned int failed_tests = 0;
    test_number++;
    if (!test_find_min_small_array()) {
        failed_tests++;
    }
    test_number++;
    if (!test_find_min_empty_array()) {
        failed_tests++;
    }
    test_number++;
    if (!test_find_min_sorted()) {
        failed_tests++;
    }
    test_number++;
    if (!test_find_min_duplicates()) {
        failed_tests++;
    }
    std::cout << "Passed " << test_number - failed_tests << "/" << test_number << endl;
}
bool test_find_min_small_array() {
    // Test small array
    unsigned int test_size = 7;
    int test_input[] = {8,0,5,2,1,6,7};
    std::cout << "Test small array {";
    display(test_input,test_size);
    std::cout << "}...";
    int start_index = 2;
    int expected = 4;
    if (find_min_location(test_input,start_index,test_size) == expected) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}
bool test_find_min_empty_array() {
    // Test empty vector
    unsigned int test_size = 0;
    int test_input[] = {};
    std::cout << "Test empty vector...";
    int start_index = 2; // Value shouldn't matter
    int expected = -1;
    if (find_min_location(test_input,start_index,test_size) == expected) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}
bool test_find_min_sorted() {
    // Test sorted
    std::cout << "Test sorted vector...";
    unsigned int test_size = 10;
    int test_input[] = {0,1,2,3,45,6,7,8,9};
    int start_index = 3;
    int expected = start_index;
    if (find_min_location(test_input,start_index,test_size) == expected) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

bool test_find_min_duplicates() {
    // Test duplicates
    unsigned int test_size = 7;
    int test_input[] = {8,1,5,2,1,6,7};
    std::cout << "Test {";
    display(test_input,test_size);
    std::cout << "}...";
    int start_index = 2;
    int expected = 4;
    if (find_min_location(test_input,start_index,test_size) == expected) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

void test_selection_sort() {
    int failed_tests = 0;
    int test_number = 0;

    test_number++;
    if (!test_selection_sort_deterministic()) {
        failed_tests++;
    }
    test_number++;
    if (!test_selection_sort_empty_array()) {
        failed_tests++;
    }
    test_number++;
    if (!test_selection_sort_sorted_array()) {
        failed_tests++;
    }
    test_number++;
    if (!test_selection_sort_reverse_sorted()) {
        failed_tests++;
    }
    test_number++;
    if (!test_selection_sort_duplicates()) {
        failed_tests++;
    }
    std::cout << "Passed " << test_number - failed_tests << "/" << test_number << endl;
}

bool test_selection_sort_deterministic() {
    // Test deterministic array
    unsigned int test_size = 7;
    int test_input[] = {8,0,5,2,1,6,7};
    std::cout << "Test small array {";
    display(test_input,test_size);
    std::cout << "}...";
    selection_sort(test_input,test_size);
    if (verify_sorted(test_input,test_size)) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

bool test_selection_sort_empty_array() {
    // Test empty array
    std::cout << "Test empty array...";
    unsigned int test_size = 0;
    int test_input[] = {};
    selection_sort(test_input,test_size);
    if (verify_sorted(test_input,test_size)) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

bool test_selection_sort_sorted_array() {
    // Test sorted
    std::cout << "Test sorted array..";
    int test_input[] = {0,1,2,3,4,5,6,7,8,9};
    unsigned int test_size = 10;
    selection_sort(test_input,test_size);
    if (verify_sorted(test_input,test_size)) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

bool test_selection_sort_reverse_sorted() {
    // Test reverse sorted
    std::cout << "Test reverse sorted...";
    unsigned int test_size = 10;
    int test_input[] = {9,8,7,6,5,4,3,2,1,0};
    selection_sort(test_input,test_size);
    if (verify_sorted(test_input,test_size)) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

bool test_selection_sort_duplicates() {
    // Test duplicates
    unsigned int test_size = 7;
    int test_input[] = {8,1,5,2,1,6,7};
    std::cout << "Test array {";
    display(test_input,test_size);
    std::cout << "}...";
    selection_sort(test_input,test_size);
    if (verify_sorted(test_input,test_size)) {
        std::cout << "Passed" << std::endl;
        return true;
    } else {
        std::cout << "Failed" << std::endl;
        return false;
    }
}

