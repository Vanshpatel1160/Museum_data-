#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <iomanip>

class Date {
public:
    int day;
    int month;
    int year;

    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getYear() const { return year; }

    std::string toString() const {
        std::ostringstream oss;
        oss << day << "/" << month << "/" << year;
        return oss.str();
    }

    int calculateAgeInYears() const {
        return 2025 - year;
    }
    

};

#endif
