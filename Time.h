#ifndef TIME_H
#define TIME_H
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>

class Time {
    private:
        double hours;
        double minutes;
    public:
        Time(double h, double m) : hours(h), minutes(m) {}
        Time() : hours(0), minutes(0) {}

        double convertToHours() const {
            return hours + (minutes / 60.0);
        }

        std::string toString() const {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(2) << hours << " hours " << minutes << " minutes";
            return oss.str();
        }
      
};
#endif // TIME_H