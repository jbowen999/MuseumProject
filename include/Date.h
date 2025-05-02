#ifndef DATE_H
#define DATE_H
#include <string>



class Date {
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y);

    std::string toString() const;

    std::string toCSVString() const;

    int getYear() const;
};


#endif //DATE_H
