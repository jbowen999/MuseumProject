#include <format>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>


#include "../include/Artwork.h"
using namespace std;


// class Time {
//     int hours;
//
// public:
//     Time(const int h) { hours(h); }
// };


class Painting : public Artwork {
public:
    enum class Medium { Oil, Acrylic, Watercolor, Mixed_Media };

private:
    static int numberOfPaintings;
    Dimensions dimensions = Dimensions(0, 0);
    string asciiArtFilename;

public:
    Medium medium;

    Painting(const string &artistFirst,
             const string &artistLast,
             const string &title, const int createdMonth,
             const int createdDay, const int createdYear,
             const int acquiredMonth, const int acquiredDay,
             const int acquiredYear, const string &donatedFirst,
             const string &donatedLast, const double w,
             const double h, const Medium medium, const std::string &asciiArtFilename) {
        setArtist(artistFirst, artistLast);
        setTitle(title);
        setCreatedDate(createdMonth, createdDay, createdYear);
        setAcquiredDate(acquiredMonth, acquiredDay, acquiredYear);
        setDonatedBy(donatedFirst, donatedLast);
        setDimensions(w, h);
        this->medium = medium;
        numberOfPaintings++;
    }

    string getMediumAsString() const {
        switch (medium) {
            case Medium::Oil: return "Oil";
            case Medium::Acrylic: return "Acrylic";
            case Medium::Watercolor: return "Watercolor";
            case Medium::Mixed_Media: return "Mixed Media";
            default: return "Unknown";
        }
    }

    string toString() const override {
        return "Painting: \"" + getTitle() + "\"\n"
               "Artist: " + getArtist().toString() + "\n"
               "Created: " + getCreatedDate().toString() + "\n"
               "Acquired: " + getAcquiredDate().toString() + "\n"
               "Donated by: " + getDonatedBy().toString() + "\n"
               "Dimensions: " + getDimensions().toString() + "\n"
               "Medium: " + getMediumAsString() + "\n"
               "Value: " + format("${:.2f}", value());
    }

    double value() const override {
        // Calculate age
        constexpr int currentYear = 2025; // or get it from system date
        const int age = currentYear - getCreatedDate().getYear();

        // Calculate area in square feet (1 sq ft = 144 sq in)
        const double areaInSquareInches = dimensions.getHeight() * dimensions.getWidth();
        const double areaInSquareFeet = areaInSquareInches / 144.0;

        // Final value
        return age * areaInSquareFeet;
    }


    void setDimensions(const double h, const double w) {
        dimensions.setHeight(h);
        dimensions.setWidth(w);
    }

    Dimensions getDimensions() const {
        return dimensions;
    }
};


int Painting::numberOfPaintings = 0;

Painting::Medium parseMedium(const std::string &str) {
    if (str == "Oil") return Painting::Medium::Oil;
    if (str == "Acrylic") return Painting::Medium::Acrylic;
    if (str == "Watercolor") return Painting::Medium::Watercolor;
    if (str == "Mixed_Media") return Painting::Medium::Mixed_Media;
    throw std::invalid_argument("Unknown medium: " + str);
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
    const Painting::Medium medium = parseMedium(fields[14]);
    const string &asciiArtFilename = fields[15];

    return Painting(
        artistFirstName, artistLastName,
        title,
        createdMonth, createdDay, createdYear,
        acquiredMonth, acquiredDay, acquiredYear,
        donatedFirst, donatedLast,
        w, h,
        medium,
        asciiArtFilename
    );
}

std::vector<std::string> split(const std::string &line, const char delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end;

    while ((end = line.find(delimiter, start)) != std::string::npos) {
        result.push_back(line.substr(start, end - start));
        start = end + 1;
    }

    // Add the last piece
    result.push_back(line.substr(start));

    return result;
}

vector<unique_ptr<Artwork> > loadData(const string &filename) {
    vector<unique_ptr<Artwork> > artworks;
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open " << filename << endl;
        return artworks;
    }

    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ','); // assume you write a 'split' helper

        if (fields.empty()) continue;

        if (fields[0] == "Painting") {
            artworks.push_back(make_unique<Painting>(createPainting(fields)));
        } else {
            cerr << "Unknown artwork type: " << fields[0] << endl;
        }
    }

    return artworks;
}


int main() {

    const string filename = "../data/artworks.csv";
    const vector<unique_ptr<Artwork> > artworks = loadData(filename);

    if (artworks.empty()) {
        cout << "No artwork loaded.\n";
        return 1;
    }

    for (const auto &art: artworks) {
        cout << art->toString() << "\n\n";
    }

    return 0;
}



