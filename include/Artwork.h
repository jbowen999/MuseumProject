#ifndef ARTWORK_H
#define ARTWORK_H
#include <vector> // including here so every other file will have it
#include "../include/Date.h"
#include "../include/Name.h"
#include "../include/Dimensions.h"

// Abstract base class representing general artwork properties
class Artwork {
    // Member variables representing the artist, title, creation date, acquisition date,
    // donor's name, and a description of the artwork.
    Name artist;
    std::string title;
    Date created;
    Date acquired;
    Name donatedBy;
    std::string description;

public:
    // Default constructor for Artwork class
    Artwork();
    // Virtual destructor to ensure proper cleanup of derived classes (polymorphism)
    virtual ~Artwork() = 0;
    // Pure virtual function to convert artwork to a string representation
    // This is a polymorphic function that needs to be implemented by derived classes.
    std::string virtual toString() const = 0;
    // Pure virtual function to calculate the value of the artwork
    // The implementation will differ between types of artworks (e.g., paintings vs. sculptures).
    double virtual value() const = 0;
    // Pure virtual function to return the artwork as a CSV-formatted string
    // Derived classes must implement this for saving the artwork data to a file.
    virtual std::string toCSV() const = 0;

    // Setters for the various attributes of the Artwork class
    void setArtist(const std::string &f, const std::string &l);
    void setTitle(const std::string &t);
    void setCreatedDate(int m, int d, int y);
    void setAcquiredDate(int m, int d, int y);
    void setDonatedBy(const std::string &f, const std::string &l);
    void setDescription(const std::string& d);

    // Getters for the various attributes of the Artwork class
    Name getArtist() const;
    std::string getTitle() const;
    Date getCreatedDate() const;
    Date getAcquiredDate() const;
    Name getDonatedBy() const;
    std::string getDescription() const;

    // Comparison operators for comparing Artwork objects
    bool operator==(const Artwork& other) const;
    bool operator!=(const Artwork& other) const;
    bool operator<(const Artwork& other) const;
    bool operator<=(const Artwork& other) const;
    bool operator>(const Artwork& other) const;
    bool operator>=(const Artwork& other) const;
};



#endif //ARTWORK_H
