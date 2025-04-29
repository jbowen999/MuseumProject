//
// Created by Julian on 4/25/2025.
//

#ifndef ARTWORK_H
#define ARTWORK_H
#include "../include/Date.h"
#include "../include/Name.h"
#include "../include/Dimensions.h"


class Artwork {
    Name artist;
    std::string title;
    Date created;
    Date acquired;
    Name donatedBy;
    std::string assciArtFilename;

public:
    Artwork();
    virtual ~Artwork() = 0;

    [[nodiscard]] std::string virtual toString() const = 0;
    [[nodiscard]] double virtual value() const = 0;

    void setArtist(const std::string &f, const std::string &l);
    void setTitle(const std::string &t);
    void setCreatedDate(const int m, const int d, const int y);
    void setAcquiredDate(const int m, const int d, const int y);
    void setDonatedBy(const std::string &f, const std::string &l);

    Name getArtist() const;
    std::string getTitle() const;
    Date getCreatedDate() const;
    Date getAcquiredDate() const;
    Name getDonatedBy() const;

    bool operator==(const Artwork& other) const;
    bool operator!=(const Artwork& other) const;
    bool operator<(const Artwork& other) const;
    bool operator<=(const Artwork& other) const;
    bool operator>(const Artwork& other) const;
    bool operator>=(const Artwork& other) const;
};



#endif //ARTWORK_H
