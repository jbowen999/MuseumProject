#include <iostream>
#include <utility>
using namespace std;

class Name {
    string firstName;
    string lastName;
public:
    Name(string   f, string   l) : firstName(std::move(f)), lastName(std::move(l)) {}

    string toString() const {
        return firstName + " " + lastName;
    }
};

class Date {
    int day;
    int month;
    int year;
public:
    Date(const int d, const int m, const int y) : day(d), month(m), year(y) {}

string toString() const {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
};

class Dimensions {
    double width;
    double height;

public:
    Dimensions(const int w, const int h) : width(w), height(h) {}

    string toString() const {
        return to_string(height) + " x " + to_string(width) + " cm";
    }
};



class ArtWork {
    Name artist;
    Date created;
    Date acquired;
    Name donatedBy;
    string description;

public:
    virtual ~ArtWork() = 0;
    string virtual toString() = 0;
    double virtual value() = 0;
};

class Painting : public ArtWork {
public:
    enum class Medium {Oil, Acrylic, Watercolor, Mixed_Media};
private:
    Medium medium;
    Dimensions dimensions;
    static int numberOfPaintings;

};

class Sculpture : public ArtWork {
public:
    enum class Medium {Ceramic, Stone, Metal, Mixed_media};
private:
    Medium medium;
};

class WrittenWord : public ArtWork {
public:
    enum class Genre {Novel, Biography, Anthology, Illustrated, Autobiography, Nonfiction,
Poetry};
private:
    Genre genre;
};

class Film : public ArtWork {
public:
    enum class Genre {Documentary, Anime, Animation, Drama, Comedy, Fantasy};
private:
    Genre genre;
};


int main() {

}