#include <iostream>
#include <fstream>
#include <memory>
#include "../include/Utility.h"

using namespace std;

int main() {

    const string filename = "../data/artworks.csv";

    if (const vector<unique_ptr<Artwork>> artworks = loadData(filename); artworks.empty()) {
        cout << "No artwork loaded.\n";

    }
    generateSampleArtworks();

    // for (const auto &art: artworks) {
    //     cout << art->toString() << "\n\n";
    // }

    // if (const Artwork* maxValueItem = findMaxValue<Artwork>(artworks)) {
    //     cout << "Most valuable artwork:\n" << maxValueItem->toString() << endl;
    // }
    //
    // cout << endl;
    //
    // if (const Artwork* maxValueItem = findMinValue<Artwork>(artworks)) {
    //     cout << "Least valuable artwork:\n" << maxValueItem->toString() << endl;
    // }

    cout << "Paintings total=" << Painting::numberOfPaintings << endl;
    cout << "Sculpture total=" << Sculpture::numberOfSculptures << endl;
    cout << "Written word item total=" << WrittenWord::numberOfWrittenWordItems << endl;

    return 0;
}
