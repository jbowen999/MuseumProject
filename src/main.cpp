#include <format>
#include <iostream>
#include "../include/Date.h"
#include "../include/Name.h"
#include "../include/Dimensions.h"
using namespace std;


// class Time {
//     int hours;
//
// public:
//     Time(const int h) { hours(h); }
// };

class Artwork {
    Name artist;
    string title;
    Date created;
    Date acquired;
    Name donatedBy;

public:
    Artwork() : artist("", ""), title(""), created(0, 0, 0), acquired(0, 0, 0), donatedBy("", "") {
    }

    virtual ~Artwork() = 0;

    string virtual toString() const = 0;

    double virtual value() const = 0;

    void setArtist(const string &f, const string &l) {
        artist = Name(f, l);
    }

    void setTitle(const string &t) {
        title = t;
    }

    void setCreatedDate(const int m, const int d, const int y) {
        created = Date(m, d, y);
    }

    void setAcquiredDate(const int m, const int d, const int y) {
        acquired = Date(m, d, y);
    }

    void setDonatedBy(const string &f, const string &l) {
        donatedBy = Name(f, l);
    }

    Name getArtist() const {
        return artist;
    }

    string getTitle() const {
        return title;
    }

    Date getCreatedDate() const {
        return created;
    }

    Date getAcquiredDate() const {
        return acquired;
    }

    Name getDonatedBy() const {
        return donatedBy;
    }

    bool operator==(const Artwork& other) const {
        return value() == other.value();
    }

    bool operator!=(const Artwork& other) const {
        return !(*this == other);
    }

    bool operator<(const Artwork& other) const {
        return value() < other.value();
    }

    bool operator<=(const Artwork& other) const {
        return value() <= other.value();
    }

    bool operator>(const Artwork& other) const {
        return value() > other.value();
    }

    bool operator>=(const Artwork& other) const {
        return value() >= other.value();
    }


};

Artwork::~Artwork() = default;


class Painting : public Artwork {
public:
    enum class Medium { Oil, Acrylic, Watercolor, Mixed_Media };

private:
    static int numberOfPaintings;
    Dimensions dimensions = Dimensions(0, 0);

public:
    Medium medium;

    Painting(const string &artistFirst, const string &artistLast, const string &title, const int createdMonth,
             const int createdDay, const int createdYear, const int acquiredMonth, const int acquiredDay,
             const int acquiredYear, const string &donatedFirst, const string &donatedLast, const double w,
             const double h,
             const Medium medium) {
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


int main() {
    auto monaLisa = Painting(
        "Leonardo", "da Vinci", // Artist name
        "Mona Lisa", // Title
        10, 1, 1503, // Created Date
        9, 14, 1797, // Acquired Date
        "Napoleon", "Bonaparte", // Donated by
        30, 21, // Dimensions
        Painting::Medium::Oil
    );

    auto starryNight = Painting(
        "Vincent", "van Gogh",
        "Starry Night",
        6, 1, 1889,
        5, 10, 1941,
        "Museum", "of Modern Art",
        29, 36.25,
        Painting::Medium::Oil
    );

    cout << "Mona Lisa:\n" << monaLisa.toString() << "\n\n";
    cout << "Starry Night:\n" << starryNight.toString() << "\n\n";

    // 🔍 Operator tests
    cout << boolalpha; // Print true/false instead of 1/0

    cout << "Mona Lisa == Starry Night? " << (monaLisa == starryNight) << endl;
    cout << "Mona Lisa != Starry Night? " << (monaLisa != starryNight) << endl;
    cout << "Mona Lisa < Starry Night? " << (monaLisa < starryNight) << endl;
    cout << "Mona Lisa <= Starry Night? " << (monaLisa <= starryNight) << endl;
    cout << "Mona Lisa > Starry Night? " << (monaLisa > starryNight) << endl;
    cout << "Mona Lisa >= Starry Night? " << (monaLisa >= starryNight) << endl;

    return 0;
}

// class Sculpture : public ArtWork {
// public:
//     enum class Medium { Ceramic, Stone, Metal, Mixed_media };
//
// private:
//     Medium medium;
// };
//
// class WrittenWord : public ArtWork {
// public:
//     enum class Genre {
//         Novel, Biography, Anthology, Illustrated, Autobiography, Nonfiction,
//         Poetry
//     };
//
// private:
//     Genre genre;
// };
//
// class Film : public ArtWork {
// public:
//     enum class Genre { Documentary, Anime, Animation, Drama, Comedy, Fantasy };
//
// private:
//     Genre genre;
// };


