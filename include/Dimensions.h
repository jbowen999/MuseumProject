//
// Created by Julian on 4/25/2025.
//

#ifndef DIMENSIONS_H
#define DIMENSIONS_H
#include <string>
#include <format>

class Dimensions {
    double width;
    double height;
public:
    Dimensions(double w, double h);

    [[nodiscard]] std::string toString() const;

    std::string toCSVString() const;

    void setWidth(double w);
    void setHeight(double h);
    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
};



#endif //DIMENSIONS_H

