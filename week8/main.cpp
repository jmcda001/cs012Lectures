#include "Employee.h"
#include "Lecturer.h"
#include "StudentEmpl.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    Employee employee1("J. Doe","900 University Ave.","j.doe@email.ucr.edu","1");
    employee1.display();
    cout << "sizeof(Employee): " << sizeof(Employee) << endl;

    StudentEmpl studentEmpl1("Scotty DaBear","900 University Ave.","sdabe001@ucr.edu","2",10,15.0);
    studentEmpl1.display();
    cout << "sizeof(StudentEmpl): " << sizeof(StudentEmpl) << endl;

    Lecturer lecturer1("E. Dijkstra","900 University Ave.","e.dijkstra@email.ucr.edu","3",7500,0.33);
    lecturer1.display();
    cout << "sizeof(lecturer1): " << sizeof(Lecturer) << endl;

    // Slice lecturer object into emplyee object
    Employee employeeLecturer = lecturer1;
    employeeLecturer.display();
    //cout << "Percentage: " << employeeLecturer.getPercentage() << endl; // compiler error
    cout << "sizeof(employeeLecturer): " << sizeof(employeeLecturer) << endl;

    {
        vector<Employee> employees;
        employees.push_back(employee1);
        employees.push_back(studentEmpl1);
        employees.push_back(lecturer1);
        employees.push_back(employeeLecturer);

        cout << endl;
        cout << "Employees: (" << employees.size() << ")" << endl;
        for (auto emp : employees) {
            cout << "typeid(): " << typeid(emp).name() << endl;
            emp.display();
            cout << endl;
        }
    }
    {
        vector<Employee*> employees;
        employees.push_back(&employee1);
        employees.push_back(&studentEmpl1);
        employees.push_back(&lecturer1);
        employees.push_back(&employeeLecturer);

        cout << endl;
        cout << "Employees: (" << employees.size() << ")" << endl;
        for (auto emp : employees) {
            cout << "typeid(): " << typeid(*emp).name() << endl;
            emp->display();
            cout << endl;
        }
    }

    {
        vector<Employee*> employees;
        employees.push_back(new Employee("J. Doe","900 University Ave.","j.doe@email.ucr.edu","1"));
        employees.push_back(new StudentEmpl("Scotty DaBear","900 University Ave.",
                    "sdabe001@ucr.edu","2",0,15.0));
        employees.push_back(new Lecturer("E. Dijkstra","900 University Ave.",
                    "e.dijkstra@email.ucr.edu","3",7500,0.33));

        cout << "Employees (employees): (" << employees.size() << ")" << endl;
        for (auto emp : employees) {
            cout << "typeid(): " << typeid(*emp).name() << endl;
            emp->display();
            cout << endl;
        }
        // emp->paycheckAmount() leads to compiler error
        // error: 'class Employee' has no member named 'paycheckAmount'
        /*double totalPayout = 0.0;
        for (auto emp : employees) {
            totalPayout += emp->paycheckAmount();
        }
        cout << "Total payout: " << totalPayout << endl;*/
    }

    return 0;
}
