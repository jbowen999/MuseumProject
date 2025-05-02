#include "../include/Artwork.h"

// Default constructor initializes members using their default constructors
Artwork::Artwork() : artist("", ""),
                     title(), created(0, 0, 0),
                     acquired(0, 0, 0), donatedBy("", ""), description() {}

// Pure virtual destructor must have a definition even if defaulted
Artwork::~Artwork() = default;

// Settters
void Artwork::setArtist(const std::string &f, const std::string &l) {
    artist = Name(f, l);
}

void Artwork::setTitle(const std::string &t) {
    title = t;
}

void Artwork::setCreatedDate(const int m, const int d, const int y) {
    created = Date(m, d, y);
}

void Artwork::setAcquiredDate(const int m, const int d, const int y) {
    acquired = Date(m, d, y);
}

void Artwork::setDonatedBy(const std::string &f, const std::string &l) {
    donatedBy = Name(f, l);
}

void Artwork::setDescription(const std::string &d) {
    description = d;
}

// Getters
Name Artwork::getArtist() const {
    return artist;
}

std::string Artwork::getTitle() const {
    return title;
}

Date Artwork::getCreatedDate() const {
    return created;
}

Date Artwork::getAcquiredDate() const {
    return acquired;
}

Name Artwork::getDonatedBy() const {
    return donatedBy;
}

std::string Artwork::getDescription() const {
    return description;
}

// Overload operators
bool Artwork::operator==(const Artwork &other) const {
    return value() == other.value();
}

bool Artwork::operator!=(const Artwork &other) const {
    return !(*this == other);
}

bool Artwork::operator<(const Artwork &other) const {
    return value() < other.value();
}

bool Artwork::operator<=(const Artwork &other) const {
    return value() <= other.value();
}

bool Artwork::operator>(const Artwork &other) const {
    return value() > other.value();
}

bool Artwork::operator>=(const Artwork &other) const {
    return value() >= other.value();
}
