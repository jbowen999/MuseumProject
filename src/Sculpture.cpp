#include "../include/Sculpture.h"

#include <sstream>


int Sculpture::numberOfSculptures = 0; // Initialize the static variable

Sculpture::Sculpture(const string &artistFirst, const string &artistLast,
                     const string &title, const int createdMonth,
                     const int createdDay, const int createdYear,
                     const int acquiredMonth, const int acquiredDay,
                     const int acquiredYear, const string &donatedFirst,
                     const string &donatedLast, const double w, const double h,
                     const double weight, const Medium medium, const string &description) {
    setArtist(artistFirst, artistLast);
    setTitle(title);
    setCreatedDate(createdMonth, createdDay, createdYear);
    setAcquiredDate(acquiredMonth, acquiredDay, acquiredYear);
    setDonatedBy(donatedFirst, donatedLast);
    setDimensions(h, w);
    this->weight = weight;
    this->medium = medium;
    setDescription(description);
    numberOfSculptures++;
}

// Getter and setter for dimensions
void Sculpture::setDimensions(const double h, const double w) {
    dimensions.setHeight(h);
    dimensions.setWidth(w);
}

Dimensions Sculpture::getDimensions() const {
    return dimensions;
}

// Helper function for toString()
string Sculpture::getMediumAsString() const {
    switch (medium) {
        case Medium::Ceramic: return "Ceramic";
        case Medium::Stone: return "Stone";
        case Medium::Metal: return "Metal";
        case Medium::Mixed_Media: return "Mixed Media";
        default: return "Unknown";
    }
}

// Helper function for parsing CSV file
Sculpture::Medium parseSculptureMedium(const std::string &str) {
    if (str == "Ceramic") return Sculpture::Medium::Ceramic;
    if (str == "Stone") return Sculpture::Medium::Stone;
    if (str == "Metal") return Sculpture::Medium::Metal;
    if (str == "Mixed_Media") return Sculpture::Medium::Mixed_Media;
    throw std::invalid_argument("Unknown medium: " + str);
}

// Override functions
string Sculpture::toString() const {
    return "Sculpture: \"" + getTitle() + "\"\n"
           "Artist: " + getArtist().toString() + "\n"
           "Description: " + getDescription() + "\n"
           "Created: " + getCreatedDate().toString() + "\n"
           "Acquired: " + getAcquiredDate().toString() + "\n"
           "Donated by: " + getDonatedBy().toString() + "\n"
           "Dimensions: " + getDimensions().toString() + "\n"
           "Weight: " + format("{:.2f} kg", weight) + "\n"
           "Medium: " + getMediumAsString() + "\n"
           "Value: " + format("${:.2f}", value());
}

double Sculpture::value() const {
    // Calculate age
    constexpr int currentYear = 2025;
    const int age = currentYear - getCreatedDate().getYear();

    return age * weight;
}

std::string Sculpture::toCSV() const {
    std::ostringstream oss;
    oss << "Sculpture,"
        << getTitle() << ","
        << getArtist().toCSVString() << ","
        << getCreatedDate().toCSVString() << ","
        << getAcquiredDate().toCSVString() << ","
        << getDonatedBy().toCSVString() << ","
        << getDimensions().toCSVString() << ","
        << format("{:.2f}", weight)<< ","
        << getMediumAsString() << ","
        << getDescription() << ",";
    return oss.str();
}

// Function to create object after csv parsing
Sculpture createSculpture(const vector<string> &fields) {
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
    const double weight = stod(fields[14]);
    const Sculpture::Medium medium = parseSculptureMedium(fields[15]);
    const string &description = fields[16];


    return Sculpture(
        artistFirstName, artistLastName,
        title,
        createdMonth, createdDay, createdYear,
        acquiredMonth, acquiredDay, acquiredYear,
        donatedFirst, donatedLast,
        w, h, weight,
        medium, description
    );
}
