#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include <string>

class Employee {
    protected: // Must be protected so child classes (inherited) can access these member variables
        std::string name;
        std::string address;
        std::string email;
        std::string eid;
    public:
        /* Constructors */
        Employee(const std::string &,const std::string &,const std::string &,const std::string &);
        /* No pointers used so no big 3 necessary
        ~Employee() // default destructor is sufficient
        Employee(const Employee &) // default copy constructor is sufficient
        Employee &operator=(const Employee &) // default copy assignment operator is sufficient
        */

        /* Accessors */
        std::string getName() const { return name; }
        std::string getAddress() const { return address; }
        std::string getEmail() const { return email; }
        std::string getEid() const { return eid; }

        /* Mutators */
        void setName(std::string &name) { this->name = name; }
        void setAddress(std::string &address) { this->address = address; }
        void setEmail(std::string &email) { this->email = email; }
        virtual void display() const;
        //void display(); // Need virtual for all functions that will be dynamically bound

        //virtual double paycheckAmount() = 0;
        // What would we define paycheckAmount to be? There is no payroll information in this class
        // Making paycheckAmount pure virtual makes the Employee class an "abstract base class"
        // We are not able to instantiate an object of an abstract base class type (compiler error)
        // There is no (required) definition of pure virtual functions. 
};
#endif // __EMPLOYEE_H__
