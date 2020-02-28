#include "StudentEmpl.h"
#include <iostream>

using namespace std;

StudentEmpl::StudentEmpl(const string &name,const string &address,
            const string &email,const string &eid,
            double numHours,double hourlyRate) : Employee(name,address,email,eid) {
    cerr << "Constructing StudentEmpl object..." << endl;
    this->numHours = numHours;
    this->hourlyRate = hourlyRate;
}

double StudentEmpl::paycheckAmount() const {
    return numHours * hourlyRate;
}
