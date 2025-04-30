//
// Created by Julian on 4/29/2025.
//

#ifndef PAINTING_H
#define PAINTING_H
#include "Artwork.h"


using namespace std;

class Painting final : public Artwork {
public:
    enum class Medium { Oil, Acrylic, Watercolor, Mixed_Media };

private:
    Dimensions dimensions = Dimensions(0, 0);
    string asciiArtFilename;

public:
    static int numberOfPaintings;
    Medium medium;

    Painting(const string &artistFirst,
             const string &artistLast,
             const string &title, int createdMonth,
             int createdDay, int createdYear,
             int acquiredMonth, int acquiredDay,
             int acquiredYear, const string &donatedFirst,
             const string &donatedLast, double w,
             double h, Medium medium, const string &asciiArtFilename);

    string getMediumAsString() const;
    string toString() const override;
    double value() const override;

    void setDimensions(double h, double w);
    Dimensions getDimensions() const;

    static int getNumberOfPaintings() { return numberOfPaintings; }

};

Painting::Medium parsePaintingMedium(const string &str);
Painting createPainting(const vector<string> &fields);


#endif //PAINTING_H
