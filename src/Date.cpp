#include "../include/Date.h"
#include <string>
Date::Date(const int m, const int d, const int y)
    : month(m), day(d), year(y) {}

std::string Date::toString() const {
    return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}

std::string Date::toCSVString() const {
    return std::to_string(month) + "," + std::to_string(day) + "," + std::to_string(year);
}

int Date::getYear() const {
    return year;
}

