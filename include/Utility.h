//
// Created by Julian on 5/2/2025.
//

#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "../include/Painting.h"
#include "../include/Sculpture.h"
#include "../include/WrittenWord.h"

// Helper function for parsing data from file
inline std::vector<std::string> split(const std::string &line, const char delimiter) {
    std::vector<std::string> result; // initialize vector
    size_t start = 0, end; // initialize start and end points

    while ((end = line.find(delimiter, start)) != std::string::npos) {
        result.push_back(line.substr(start, end - start));
        start = end + 1;
    } // loop through the line until it gets to the last item

    result.push_back(line.substr(start)); // last piece

    return result;
}

// loads data from file
inline std::vector<unique_ptr<Artwork>> loadData(const string &filename) {
    vector<unique_ptr<Artwork> > artworks; // initialize vector to be returned
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open " << filename << endl;
        return artworks;
    }

    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ','); // call the split function with ',' as delimiter

        if (fields.empty()) continue;

        // Branch to decide what kind of artwork is being read
        if (fields[0] == "Painting") {
            artworks.push_back(make_unique<Painting>(createPainting(fields)));
        } else if (fields[0] == "Sculpture") {
            artworks.push_back(make_unique<Sculpture>(createSculpture(fields)));
        } else if (fields[0] == "WrittenWord") {
            artworks.push_back(make_unique<WrittenWord>(createWrittenWord(fields)));
        }
        else {
            cerr << "Unknown artwork type: " << fields[0] << endl;
        }
    }

    return artworks;
}

inline vector<unique_ptr<Artwork>> generateSampleArtworks() {
    vector<unique_ptr<Artwork>> sampleArtworks;

    // Two Paintings
    sampleArtworks.push_back(make_unique<Painting>(
        "Vincent", "van Gogh", "Irises",
        5, 1, 1889, 7, 14, 1945,
        "Theo", "van Gogh",
        29.0, 37.0,
        Painting::Medium::Oil,
        "A vibrant flower study from van Gogh's time in an asylum."
    ));

    sampleArtworks.push_back(make_unique<Painting>(
        "Frida", "Kahlo", "The Two Fridas",
        10, 1, 1939, 12, 20, 1955,
        "Diego", "Rivera",
        68.0, 68.0,
        Painting::Medium::Acrylic,
        "A powerful double self-portrait showing emotional conflict."
    ));

    // Two Sculptures
    sampleArtworks.push_back(make_unique<Sculpture>(
        "Constantin", "Brancusi", "Bird in Space",
        3, 1, 1923, 5, 12, 1931,
        "John", "Quinn",
        12.0, 48.0, 2000.0,
        Sculpture::Medium::Metal,
        "A sleek, abstract form that evokes the motion of flight."
    ));

    sampleArtworks.push_back(make_unique<Sculpture>(
        "Louise", "Bourgeois", "Maman",
        6, 1, 1999, 4, 15, 2005,
        "Tate", "Modern",
        33.0, 100.0, 5000.0,
        Sculpture::Medium::Mixed_Media,
        "A towering spider sculpture symbolizing motherhood and strength."
    ));

    // Two WrittenWord
    sampleArtworks.push_back(make_unique<WrittenWord>(
        "Emily", "Bronte", "Wuthering Heights",
        12, 1, 1847, 3, 20, 1920,
        "Charlotte", "Bronte",
        416,
        WrittenWord::Medium::Novel,
        "A dark and stormy tale of passion and revenge on the moors."
    ));

    sampleArtworks.push_back(make_unique<WrittenWord>(
        "Walt", "Whitman", "Leaves of Grass",
        7, 4, 1855, 5, 10, 1900,
        "Sarah", "Allen",
        144,
        WrittenWord::Medium::Poetry,
        "A landmark American poetry collection celebrating nature and self."
    ));


    return sampleArtworks;
}

template<typename T>
T* findMaxValue(const std::vector<unique_ptr<Artwork>>& items) {
    if (items.empty()) return nullptr;
    T* maxItem = items[0].get();

    for (const auto& item : items) {
        if (item->value() > maxItem->value()) {
            maxItem = item.get();
        }
    }
    return maxItem;
}

template<typename T>
T* findMinValue(const std::vector<unique_ptr<Artwork>>& items) {
    if (items.empty()) return nullptr;
    T* minItem = items[0].get();

    for (const auto& item : items) {
        if (item->value() < minItem->value()) {
            minItem = item.get();
        }
    }
    return minItem;
}

void partitionArtworks(const std::vector<std::unique_ptr<Artwork>>& artworks,
                       std::vector<std::unique_ptr<Painting>>& paintings,
                       std::vector<std::unique_ptr<Sculpture>>& sculptures,
                       std::vector<std::unique_ptr<WrittenWord>>& writtenWords) {
    for (const auto& artwork : artworks) {
        if (auto const painting = dynamic_cast<Painting*>(artwork.get())) {
            // 'artwork' is a pointer to an Artwork object,
            // and we're trying to cast it to a Painting pointer.
            paintings.push_back(std::make_unique<Painting>(*painting));  // Copy the Painting object
        } else if (auto const sculpture = dynamic_cast<Sculpture*>(artwork.get())) {
            sculptures.push_back(std::make_unique<Sculpture>(*sculpture));  // Copy the Sculpture object
        } else if (auto const writtenWord = dynamic_cast<WrittenWord*>(artwork.get())) {
            writtenWords.push_back(std::make_unique<WrittenWord>(*writtenWord));  // Copy the WrittenWord object
        }
    }
}

template<typename T>
void printCollectionTitles(const std::vector<unique_ptr<T>>& items) {
    if (items.empty()) {
        cout << "No items in this collection.\n";
        return;
    }
    for (const auto& item : items) {
        cout << item->getTitle() << "\n\n";
    }
}

template<typename T>
void printCollectionStrings(const std::vector<unique_ptr<T>>& items) {
    if (items.empty()) {
        cout << "No items in this collection.\n";
        return;
    }
    for (const auto& item : items) {
        cout << item->toString() << "\n\n";
    }
}


template<typename T>
bool getInput(T &input) {
    cin >> input;
    if (cin.fail()) {
        cin.clear(); // Clears the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores invalid input
        return false;
    }
    return true;
}



#endif //UTILITY_H
