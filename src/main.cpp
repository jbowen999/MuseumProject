#include <iostream>
#include <fstream>
#include <memory>
#include "../include/Painting.h"
#include "../include/Sculpture.h"
#include "../include/WrittenWord.h"

using namespace std;

// Helper function for parsing data from file
std::vector<std::string> split(const std::string &line, const char delimiter) {
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
vector<unique_ptr<Artwork> > loadData(const string &filename) {
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


int main() {

    const string filename = "../data/artworks.csv";
    const vector<unique_ptr<Artwork> > artworks = loadData(filename);

    if (artworks.empty()) {
        cout << "No artwork loaded.\n";
        return 1;
    }

    for (const auto &art: artworks) {
        cout << art->toString() << "\n\n";
    }

    cout << "Paintings total=" << Painting::numberOfPaintings << endl;
    cout << "Paintings total=" << Sculpture::numberOfSculptures << endl;
    cout << "Paintings total=" << WrittenWord::numberOfWrittenWordItems << endl;

    return 0;
}
