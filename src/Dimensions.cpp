#include "../include/Dimensions.h"

Dimensions::Dimensions(const double w, const double h)
    :width(w), height(h) {}

std::string Dimensions::toString() const {
    return std::format("{:.2f} x {:.2f} in", width, height);
}

std::string Dimensions::toCSVString() const {
    return std::format("{:.2f},{:.2f}", width, height);
}


void Dimensions::setWidth(const double w) {
    width = w;
}

void Dimensions::setHeight(const double h) {
    height = h;
}

double Dimensions::getWidth() const {
    return width;
}

double Dimensions::getHeight() const {
    return height;
}