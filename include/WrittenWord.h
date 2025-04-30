//
// Created by Julian on 4/29/2025.
//

#ifndef WRITTENWORD_H
#define WRITTENWORD_H
#include "Artwork.h"

using namespace std;

class WrittenWord final : public Artwork {
public:
    enum class Medium { Novel, Biography, Anthology, Illustrated, Autobiography, Nonfiction, Poetry};

private:
    int numPages = 0;
    string asciiArtFilename;

public:
    static int numberOfWrittenWordItems;
    Medium medium;

    WrittenWord(const string &artistFirst,
             const string &artistLast,
             const string &title, int createdMonth,
             int createdDay, int createdYear,
             int acquiredMonth, int acquiredDay,
             int acquiredYear, const string &donatedFirst,
             const string &donatedLast, int numPages, Medium medium);

    string getMediumAsString() const;
    string toString() const override;
    double value() const override;

    void setDimensions(double h, double w);
    Dimensions getDimensions() const;

    static int getNumberOfWrittenWordItems() { return numberOfWrittenWordItems; }

};

WrittenWord::Medium parseWrittenWordMedium(const string &str);
WrittenWord createWrittenWord(const vector<string> &fields);





#endif //WRITTENWORD_H
