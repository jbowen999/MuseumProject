#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
    std::string firstName;
    std::string lastName;

public:
    Name(std::string f, std::string l);
    std::string toString() const;

    std::string toCSVString() const;
};



#endif //NAME_H
