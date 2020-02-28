#include "Lecturer.h"
#include <iostream>

using namespace std;

Lecturer::Lecturer(const std::string &name,const std::string &address,
            const std::string &email,const std::string &eid,
            double courseRate,double percentage) : Employee(name,address,email,eid) {
    cerr << "Constructing Lecturer object..." << endl;
    this->courseRate = courseRate;
    this->percentage = percentage;
}

void Lecturer::display() const {
#ifdef _USE_PROTECTED
    cout << "Employee \"" << name << "\"" << endl
        << "\tAddress: " << address << endl
        << "\tEmail: " << email << endl
        << "\tEID: " << eid << endl;
    cout << "\tCourse rate: " << courseRate << endl
        << "\tPercentage: " << percentage << endl;
#else
    cout << "Employee \"" << this->getName() << "\"" << endl
        << "\tAddress: " << this->getAddress() << endl
        << "\tEmail: " << this->getEmail() << endl
        << "\tEID: " << this->getEid() << endl;
    cout << "\tCourse rate: " << this->courseRate << endl
        << "\tPercentage: " << this->percentage << endl;
#endif
}

// Using Employee base display
/*void Lecturer::display() {
    Employee::display();
    cout << "\tCourse rate: " << courseRate << endl
        << "\tPercentage: " << percentage << endl;
}*/

double Lecturer::paycheckAmount() const {
    const int FULLTIME = 9;
    const int MONTHS = 12;
    return (courseRate * FULLTIME * percentage) / MONTHS;
}
