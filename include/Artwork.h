//
// Created by Julian on 4/25/2025.
//

#ifndef ARTWORK_H
#define ARTWORK_H
#include <vector> // including here so every other file will have it
#include "../include/Date.h"
#include "../include/Name.h"
#include "../include/Dimensions.h"


class Artwork {
    Name artist;
    std::string title;
    Date created;
    Date acquired;
    Name donatedBy;
    std::string description;

public:
    Artwork();
    virtual ~Artwork() = 0;

    std::string virtual toString() const = 0;
    double virtual value() const = 0;

    void setArtist(const std::string &f, const std::string &l);
    void setTitle(const std::string &t);
    void setCreatedDate(int m, int d, int y);
    void setAcquiredDate(int m, int d, int y);
    void setDonatedBy(const std::string &f, const std::string &l);
    void setDescription(const std::string& d);

    Name getArtist() const;
    std::string getTitle() const;
    Date getCreatedDate() const;
    Date getAcquiredDate() const;
    Name getDonatedBy() const;
    std::string getDescription() const;

    bool operator==(const Artwork& other) const;
    bool operator!=(const Artwork& other) const;
    bool operator<(const Artwork& other) const;
    bool operator<=(const Artwork& other) const;
    bool operator>(const Artwork& other) const;
    bool operator>=(const Artwork& other) const;
};



#endif //ARTWORK_H
