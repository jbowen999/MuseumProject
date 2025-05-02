#ifndef DIMENSIONS_H
#define DIMENSIONS_H
#include <string>
#include <format>

class Dimensions {
    double width;
    double height;
public:
    Dimensions(double w, double h);

    std::string toString() const;

    std::string toCSVString() const;

    void setWidth(double w);
    void setHeight(double h);
    double getWidth() const;
    double getHeight() const;
};



#endif //DIMENSIONS_H

