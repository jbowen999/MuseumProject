#ifndef WRITTENWORD_H
#define WRITTENWORD_H
#include "Artwork.h"

using namespace std;

class WrittenWord final : public Artwork {
public:
    enum class Medium { Novel, Biography, Anthology, Illustrated, Autobiography, Nonfiction, Poetry};

private:
    int numPages = 0;
    Medium medium;

public:
    static int numberOfWrittenWordItems;

    WrittenWord(const string &artistFirst,
             const string &artistLast,
             const string &title, int createdMonth,
             int createdDay, int createdYear,
             int acquiredMonth, int acquiredDay,
             int acquiredYear, const string &donatedFirst,
             const string &donatedLast, int numPages, Medium medium, const string& description);

    string getMediumAsString() const;
    string toString() const override;
    double value() const override;
    std::string toCSV() const override;


    void setDimensions(double h, double w);
    Dimensions getDimensions() const;

    static int getNumberOfWrittenWordItems() { return numberOfWrittenWordItems; }

};

WrittenWord::Medium parseWrittenWordMedium(const string &str);
WrittenWord createWrittenWord(const vector<string> &fields);





#endif //WRITTENWORD_H
