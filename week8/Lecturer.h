#ifndef __LECTURER_H__
#define __LECTURER_H__

#include "Employee.h"

class Lecturer: public Employee {
    private:
        /* Inherited from Employee
            std::string name;
            std::string address;
            std::string email;
            std::string eid;
        */
        double courseRate;
        double percentage;
    public:
        /* Constructors */
        Lecturer(const std::string &,const std::string &,const std::string &,const std::string &,
                double,double);

        /* Accessors */
        double getCourseRate() const { return courseRate; }
        double getPercentage() const { return percentage; }
        double paycheckAmount() const;

        /* Mutators */
        void setCourseRate(double courseRate) { this->courseRate = courseRate; }
        void setPercentage(double percentage) { this->percentage = percentage; }

        // Overrides base class definition of display()
        // The 'override' keyword indicates that the function overrides a function of the base class
        // 'Employee'. If the signature does not match, or the base class function is not marked 
        // virtual the program won't compile. 
        void display() const override; 
};
#endif // __LECTURER_H__
