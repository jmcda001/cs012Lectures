#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(const std::string &name,
        const std::string &address,
        const std::string &email,
        const std::string &eid) 
        : name{name}, address{address}, email{email}, eid{eid} { 
    cerr << "Constructing Employee object..." << endl;
}

void Employee::display() const { 
    cout << "Employee \"" << name << "\"" << endl
        << "\tAddress: " << address << endl
        << "\tEmail: " << email << endl
        << "\tEID: " << eid << endl;
}

