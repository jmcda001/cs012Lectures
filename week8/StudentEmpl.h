#ifndef __STUDENTEMPL_H__
#define __STUDENTEMPL_H__

#include "Employee.h"

class StudentEmpl: public Employee {
    private:
        /* Inherited from Employee
            std::string name;
            std::string address;
            std::string email;
            std::string eid;
        */
        double numHours;
        double hourlyRate;
    public:
        /* Constructors */
        StudentEmpl(const std::string &,const std::string &,const std::string &,const std::string &,
                double,double);

        /* Accessors */
        double getNumHours() const { return numHours; }
        double getHourlyRate() const { return hourlyRate; }
        double paycheckAmount() const;

        /* Mutators */
        void setNumHours(double numHours) { this->numHours = numHours; }
        void setHourlyRate(double hourlyRate) { this->hourlyRate = hourlyRate; }
};
#endif // __STUDENTEMPL_H__
