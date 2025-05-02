//
// Created by Julian on 4/25/2025.
//

#include "../include/Name.h"
#include <utility>

Name::Name(std::string f, std::string l)
    : firstName(std::move(f)), lastName(std::move(l)) {}

std::string Name::toString() const {
    return firstName + " " + lastName;
}

std::string Name::toCSVString() const {
    return firstName + "," + lastName;

}
