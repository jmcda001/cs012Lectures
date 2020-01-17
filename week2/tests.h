void test_verify_sorted();
void test_read_input();

void run_tests() {
    //test_verify_sorted();
    test_read_input();
}

void test_read_input() {
    int failed_tests = 0;
    int test_number = 0;
    string test_filename;
    vector<int> expected;
    vector<int> result;
    ifstream tin;

    // Test multiline input (.csv)
    test_number++;
    test_filename = "tests/test_input_multiline.csv";
    std::cout << "Test " << test_number << ": Testing \"" << test_filename << "\"...";
    expected = {1,2,3,4,5,6,7,8,9,10};
    result.clear();
    tin.open(test_filename);
    if (!tin.is_open()) { 
        cerr << "Error opening " << test_filename << endl;
        exit(1);
    }
    read_input(tin,result,true);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    tin.close();
    // Test multiline input (.txt)
    test_number++;
    test_filename = "tests/test_input_multiline.txt";
    std::cout << "Test " << test_number << ": Testing \"" << test_filename << "\"...";
    expected = {1,2,3,4,5,6,7,8,9,10};
    result.clear();
    tin.open(test_filename);
    if (!tin.is_open()) { 
        cerr << "Error opening " << test_filename << endl;
        exit(1);
    }
    read_input(tin,result);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    tin.close();
    // Test incorrect input (character) (.csv)
    test_number++;
    test_filename = "tests/test_incorrect_input.csv";
    std::cout << "Test " << test_number << ": Testing \"" << test_filename << "\"...";
    expected = {};
    result.clear();
    tin.open(test_filename);
    if (!tin.is_open()) { 
        cerr << "Error opening " << test_filename << endl;
        exit(1);
    }
    read_input(tin,result);
    if (tin.fail()) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    tin.close();
    // Test incorrect input (character) (.txt)
    test_number++;
    test_filename = "tests/test_incorrect_input.txt";
    std::cout << "Test " << test_number << ": Testing \"" << test_filename << "\"...";
    expected = {};
    result.clear();
    tin.open(test_filename);
    if (!tin.is_open()) { 
        cerr << "Error opening " << test_filename << endl;
        exit(1);
    }
    read_input(tin,result);
    if (tin.fail()) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    tin.close();
    // Test correct input (.csv)
    test_number++;
    test_filename = "tests/test_input.csv";
    std::cout << "Test " << test_number << ": Testing \"" << test_filename << "\"...";
    expected = {1,2,3,4,5,6,7,8,9,10};
    result.clear();
    tin.open(test_filename);
    if (!tin.is_open()) { 
        cerr << "Error opening " << test_filename << endl;
        exit(1);
    }
    read_input(tin,result,true);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    tin.close();
    // Test correct input (.txt)
    test_number++;
    test_filename = "tests/test_input.txt";
    std::cout << "Test " << test_number << ": Testing \"" << test_filename << "\"...";
    expected = {1,2,3,4,5,6,7,8,9,10};
    result.clear();
    tin.open(test_filename);
    if (!tin.is_open()) { 
        cerr << "Error opening " << test_filename << endl;
        exit(1);
    }
    read_input(tin,result);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    tin.close();
    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << endl;
}

void test_verify_sorted() {
    int failed_tests = 0;
    int test_number = 0;

    // Tests for sorted
    test_number++;
    vector<int> test_input = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Test " << test_number << ": Verify sorted vector is sorted...";
    bool expected = true;
    bool result = verify_sorted(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    test_number++;
    std::cout << "Test " << test_number << ": Verify sorted vector is not reverse sorted...";
    expected = false;
    result = verify_sorted(test_input,true);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Tests for Reverse sorted
    test_number++;
    test_input = {10,9,8,7,6,5,4,3,2,1};
    std::cout << "Test " << test_number << ": Verify reverse sorted vector is not sorted...";
    expected = false;
    result = verify_sorted(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }
    test_number++;
    std::cout << "Test " << test_number << ": Verify reverse sorted vector is reverse sorted...";
    expected = true;
    result = verify_sorted(test_input,true);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Unsorted on first element
    test_number++;
    test_input = {2,1,2,3,4,5,6};
    std::cout << "Test " << test_number << ": Test {";
    display(test_input);
    cout << "}...";
    expected = false;
    result = verify_sorted(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Unsorted on last element
    test_number++;
    test_input = {0,1,2,3,4,5,4};
    std::cout << "Test " << test_number << ": Test {";
    display(test_input);
    cout << "}...";
    expected = false;
    result = verify_sorted(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    // Test duplicates
    test_number++;
    test_input = {0,1,2,3,5,5,6};
    std::cout << "Test " << test_number << ": Test {";
    display(test_input);
    cout << "}...";
    expected = true;
    result = verify_sorted(test_input);
    if (result == expected) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
        failed_tests++;
    }

    std::cout << "Passed " << (test_number - failed_tests) << "/" << test_number << endl;
}
