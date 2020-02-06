#ifndef __TIME_H_
#define __TIME_H_

#include <ostream>

class Time {
    private:
        unsigned int hours;   // 0 - 23
        unsigned int minutes; // 0 - 59
    public:
        Time(); // Default is 0:0
        Time(unsigned,unsigned);
        Time(unsigned); // Explicit assumes time in minutes

        /* Operators */
        const Time operator++();
        const Time operator++(int);
        const Time operator+(const Time& rhs) const;
        friend std::ostream &operator<<(std::ostream&,const Time&);
};

#endif // __TIME_H_
