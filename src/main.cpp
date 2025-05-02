#include <iostream>
#include <fstream>
#include <memory>
#include "../include/Utility.h"

using namespace std;

int main() {
    //     What would you like to do?
    // 1. View all artworks
    // 2. View only paintings
    // 3. View only sculptures
    // 4. View only written works
    // 5. Sort artworks by value (ascending/descending)
    // 6. Find most valuable artwork
    // 7. Exit

    const string filename = "../data/artworks.csv";

    const vector<unique_ptr<Artwork> > artworks = loadData(filename);
    constexpr vector<unique_ptr<Artwork> > user_collection;
    generateSampleArtworks();
    vector<unique_ptr<Painting> > paintings;
    vector<unique_ptr<Sculpture> > sculptures;
    vector<unique_ptr<WrittenWord> > writtenWords;
    partitionArtworks(artworks, paintings, sculptures, writtenWords);


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

    const int totalItems = Painting::numberOfPaintings + Sculpture::numberOfSculptures +
                           WrittenWord::numberOfWrittenWordItems;
    cout << "Paintings total= " << Painting::numberOfPaintings << endl;
    cout << "Sculpture total= " << Sculpture::numberOfSculptures << endl;
    cout << "Written word item total= " << WrittenWord::numberOfWrittenWordItems << endl;
    cout << "Total Items= " << totalItems << endl;

    return 0;
}
