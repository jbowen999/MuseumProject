//
// Created by Julian on 4/29/2025.
//

#ifndef SCULPTURE_H
#define SCULPTURE_H
#include "Artwork.h"

using namespace std;

class Sculpture final : public Artwork {
public:
    enum class Medium { Ceramic, Stone, Metal, Mixed_Media };

private:
    Dimensions dimensions = Dimensions(0, 0);
    double weight = 0;
    Medium medium;

public:
    static int numberOfSculptures;

    Sculpture(const string &artistFirst,
             const string &artistLast,
             const string &title, int createdMonth,
             int createdDay, int createdYear,
             int acquiredMonth, int acquiredDay,
             int acquiredYear, const string &donatedFirst,
             const string &donatedLast, double w,
             double h, double weight, Medium medium, const string& description);

    string getMediumAsString() const;
    string toString() const override;
    double value() const override;

    void setDimensions(double h, double w);
    Dimensions getDimensions() const;
    void setWeight(double w);
    double getWeight() const;

    static int getNumberOfSculptures() { return numberOfSculptures; }

};

Sculpture::Medium parseSculptureMedium(const string &str);
Sculpture createSculpture(const vector<string> &fields);



#endif //SCULPTURE_H
