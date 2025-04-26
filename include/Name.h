//
// Created by Julian on 4/25/2025.
//

#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
    std::string firstName;
    std::string lastName;

public:
    Name(std::string f, std::string l);
    [[nodiscard]] std::string toString() const;
};



#endif //NAME_H
