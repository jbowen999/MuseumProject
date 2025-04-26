//
// Created by Julian on 4/25/2025.
//

#ifndef DATE_H
#define DATE_H
#include <string>



class Date {
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y);
    [[nodiscard]] std::string toString() const;
    [[nodiscard]] int getYear() const;
};


#endif //DATE_H
