//
// Created by Julian on 4/29/2025.
//

#include "../include/Painting.h"

int Painting::numberOfPaintings = 0; // Initialize the static variable

Painting::Painting(const string &artistFirst, const string &artistLast,
                   const string &title, const int createdMonth,
                   const int createdDay, const int createdYear,
                   const int acquiredMonth, const int acquiredDay,
                   const int acquiredYear, const string &donatedFirst,
                   const string &donatedLast, const double w, const double h,
                   const Medium medium, const string &description) {
    setArtist(artistFirst, artistLast);
    setTitle(title);
    setCreatedDate(createdMonth, createdDay, createdYear);
    setAcquiredDate(acquiredMonth, acquiredDay, acquiredYear);
    setDonatedBy(donatedFirst, donatedLast);
    setDimensions(h, w);
    this->medium = medium;
    setDescription(description);
    numberOfPaintings++;
}

void Painting::setDimensions(const double h, const double w) {
    dimensions.setHeight(h);
    dimensions.setWidth(w);
}

Dimensions Painting::getDimensions() const {
    return dimensions;
}

string Painting::getMediumAsString() const {
    switch (medium) {
        case Medium::Oil: return "Oil";
        case Medium::Acrylic: return "Acrylic";
        case Medium::Watercolor: return "Watercolor";
        case Medium::Mixed_Media: return "Mixed Media";
        default: return "Unknown";
    }
}

Painting::Medium parsePaintingMedium(const std::string &str) {
    if (str == "Oil") return Painting::Medium::Oil;
    if (str == "Acrylic") return Painting::Medium::Acrylic;
    if (str == "Watercolor") return Painting::Medium::Watercolor;
    if (str == "Mixed_Media") return Painting::Medium::Mixed_Media;
    throw std::invalid_argument("Unknown medium: " + str);
}

string Painting::toString() const {
    return "Painting: \"" + getTitle() + "\"\n"
           "Artist: " + getArtist().toString() + "\n"
           "Description: " + getDescription() + "\n"
           "Created: " + getCreatedDate().toString() + "\n"
           "Acquired: " + getAcquiredDate().toString() + "\n"
           "Donated by: " + getDonatedBy().toString() + "\n"
           "Dimensions: " + getDimensions().toString() + "\n"
           "Medium: " + getMediumAsString() + "\n"
           "Value: " + format("${:.2f}", value());
}

double Painting::value() const {
    // Calculate age
    constexpr int currentYear = 2025;
    const int age = currentYear - getCreatedDate().getYear();

    // Calculate area in square feet (1 sq ft = 144 sq in)
    const double areaInSquareInches = dimensions.getHeight() * dimensions.getWidth();
    const double areaInSquareFeet = areaInSquareInches / 144.0;

    return age * areaInSquareFeet;
}

Painting createPainting(const vector<string> &fields) {
    const string &artistFirstName = fields[1];
    const string &artistLastName = fields[2];
    const string &title = fields[3];
    const int createdMonth = stoi(fields[4]);
    const int createdDay = stoi(fields[5]);
    const int createdYear = stoi(fields[6]);
    const int acquiredMonth = stoi(fields[7]);
    const int acquiredDay = stoi(fields[8]);
    const int acquiredYear = stoi(fields[9]);
    const string &donatedFirst = fields[10];
    const string &donatedLast = fields[11];
    const double w = stod(fields[12]);
    const double h = stod(fields[13]);
    const Painting::Medium medium = parsePaintingMedium(fields[14]);
    const string &description = fields[15];

    return Painting(
        artistFirstName, artistLastName,
        title,
        createdMonth, createdDay, createdYear,
        acquiredMonth, acquiredDay, acquiredYear,
        donatedFirst, donatedLast,
        w, h,
        medium, description
    );
}
