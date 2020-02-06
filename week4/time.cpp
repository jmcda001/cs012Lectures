#include <ostream>
#include "time.h"

using namespace std;

Time::Time() { // Default is 0:0
    this->hours = 0;
    this->minutes = 0;
}
Time::Time(unsigned h,unsigned m = 0) {
    this->minutes = m % 60;
    this->hours = (h + (m / 60)) % 24;
}
Time::Time(unsigned m) { // Explicit assumes time in minutes
    this->minutes = m % 60;
    this->hours = (m / 60) % 24;
}

/* Operators */
const Time Time::operator+(const Time& rhs) const {
    unsigned int minutes = rhs.minutes + this->minutes;
    unsigned int hours = ((minutes / 60) + this->hours + rhs.hours) % 24;
    minutes = minutes % 60;
    return Time(hours,minutes);
}

// Prefix ++ operator
const Time Time::operator++() {
    ++this->minutes;
    if (this->minutes >= 60) {
        ++this->hours;
        this->minutes -= 60;
    }
    return Time(hours,minutes);
}

// Postfix ++ operator
const Time Time::operator++(int) {
    Time T(this->hours,this->minutes);
    ++this->minutes;
    if (this->minutes >= 60) {
        ++this->hours;
        this->minutes -= 60;
    }
    return T; // Return old value
}

ostream &operator<<(ostream &out,const Time &rhs) {
    out << rhs.hours << ':' << rhs.minutes;
    return out;
}
