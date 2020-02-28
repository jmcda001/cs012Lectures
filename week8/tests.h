#include "Employee.h"
#include "Lecturer.h"
#include "StudentEmpl.h"
#include <iostream>

using namespace std;
void test_employee();
void test_lecturer();
void test_studentEmpl();

void run_tests() {
    cout << "Testing Employee class..." << endl;
    test_employee();
    cout << endl;
    test_lecturer();
    cout << endl;
    test_studentEmpl();
    cout << endl;
}

void test_lecturer() {
    static_assert(is_base_of<Employee,Lecturer>::value,"Lecturer inerhits from Employee");
    int failed_tests = 0;
    int test_number = 0;

    // Test description
    test_number++;
    {
        string test_name = "t. name", 
               test_address = "address testing", 
               test_email = "tnam@test.com",
               test_eid = "0001";
        double test_courseRate = 7500.00,
            test_percentage = 0.33;
        Lecturer l1(test_name,test_address,test_email,test_eid,test_courseRate,test_percentage);
        cout << "Test " << test_number << ": test constructor...";
        if (l1.getName() == test_name && l1.getAddress() == test_address && 
                l1.getEmail() == test_email && l1.getEid() == test_eid &&
                l1.getCourseRate() == test_courseRate && l1.getPercentage() == test_percentage) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
    }

    test_number++;
    {
        cout << "Testing mutators on empty employee..." << endl;
        string test_name = "t. name", 
               test_address = "address testing", 
               test_email = "tnam@test.com",
               test_eid = "0001";
        double test_courseRate = 7500.00,
            test_percentage = 0.33;
        Lecturer l1("","","","",0.0,0.0);
        l1.setName(test_name);
        cout << "Test " << test_number << ": test setName()...";
        if (l1.getName() == test_name) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        l1.setAddress(test_address);
        cout << "Test " << test_number << ": test setAddress()...";
        if (l1.getAddress() == test_address) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        l1.setEmail(test_email);
        cout << "Test " << test_number << ": test setEmail()...";
        if (l1.getEmail() == test_email) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        l1.setCourseRate(test_courseRate);
        cout << "Test " << test_number << ": test setCourseRate()...";
        if (l1.getCourseRate() == test_courseRate) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        l1.setPercentage(test_percentage);
        cout << "Test " << test_number << ": test setPercentage()...";
        if (l1.getPercentage() == test_percentage) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        cout << "Test " << test_number << ": test paycheckAmount()...";
        double expected_amount = 1856.25;
        if (l1.paycheckAmount() == expected_amount) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
    }

    cout << "Passed " << (test_number - failed_tests) << "/" << test_number << endl;
}

void test_studentEmpl() {
    // static_assert is a compile time assertion. If the first parameter (boolean) is false, compilation
    // will fail and the second message (string) will be output. This helps to provide better compile 
    // time error messages.
    // is_base_of<base,derived> from the type_traits library returns true if 'derived' is a derived class 
    // of the 'base' class and false otherwise
    static_assert(is_base_of<Employee,StudentEmpl>::value,"StudentEmpl inerhits from Employee");
    int failed_tests = 0;
    int test_number = 0;

    // Test description
    test_number++;
    {
        string test_name = "t. name", 
               test_address = "address testing", 
               test_email = "tnam@test.com",
               test_eid = "0001";
        double test_hourlyRate = 15.00,
               test_numHours = 10;
        StudentEmpl e1(test_name,test_address,test_email,test_eid,test_numHours,test_hourlyRate);
        cout << "Test " << test_number << ": test constructor...";
        if (e1.getName() == test_name && e1.getAddress() == test_address && 
                e1.getEmail() == test_email && e1.getEid() == test_eid &&
                e1.getNumHours() == test_numHours && e1.getHourlyRate() == test_hourlyRate) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
    }

    test_number++;
    {
        cout << "Testing mutators on empty employee..." << endl;
        string test_name = "t. name", 
               test_address = "address testing", 
               test_email = "tnam@test.com",
               test_eid = "0001";
        double test_hourlyRate = 15.5,
               test_numHours = 10;
        StudentEmpl e1("","","","",0.0,0.0);
        e1.setName(test_name);
        cout << "Test " << test_number << ": test setName()...";
        if (e1.getName() == test_name) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        e1.setAddress(test_address);
        cout << "Test " << test_number << ": test setAddress()...";
        if (e1.getAddress() == test_address) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        e1.setEmail(test_email);
        cout << "Test " << test_number << ": test setEmail()...";
        if (e1.getEmail() == test_email) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        e1.setNumHours(test_numHours);
        cout << "Test " << test_number << ": test setNumHours()...";
        if (e1.getNumHours() == test_numHours) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        e1.setHourlyRate(test_hourlyRate);
        cout << "Test " << test_number << ": test setHourlyRate()...";
        if (e1.getHourlyRate() == test_hourlyRate) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        cout << "Test " << test_number << ": test paycheckAmount()...";
        double expected_amount = 155;
        if (e1.paycheckAmount() == expected_amount) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
    }

    cout << "Passed " << (test_number - failed_tests) << "/" << test_number << endl;
}

void test_employee() {
    //static_assert(is_abstract<Lecturer>::value,"Employee must be abstract");
    int failed_tests = 0;
    int test_number = 0;

    // Test description
    test_number++;
    {
        string test_name = "t. name", 
               test_address = "address testing", 
               test_email = "tnam@test.com",
               test_eid = "0001";
        Employee e1(test_name,test_address,test_email,test_eid);
        cout << "Test " << test_number << ": test constructor...";
        if (e1.getName() == test_name && e1.getAddress() == test_address && 
                e1.getEmail() == test_email && e1.getEid() == test_eid) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
    }

    test_number++;
    {
        cout << "Testing mutators on empty employee..." << endl;
        string test_name = "t. name", 
               test_address = "address testing", 
               test_email = "tnam@test.com",
               test_eid = "0001";
        Employee e1("","","","");
        e1.setName(test_name);
        cout << "Test " << test_number << ": test setName()...";
        if (e1.getName() == test_name) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        e1.setAddress(test_address);
        cout << "Test " << test_number << ": test setAddress()...";
        if (e1.getAddress() == test_address) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
        test_number++;
        e1.setEmail(test_email);
        cout << "Test " << test_number << ": test setEmail()...";
        if (e1.getEmail() == test_email) {
            cout << "Passed" << endl;
        } else {
            cout << "Failed" << endl;
            failed_tests++;
        }
    }

    cout << "Passed " << (test_number - failed_tests) << "/" << test_number << endl;
}
