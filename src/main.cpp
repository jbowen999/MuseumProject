#include <iostream>
#include <fstream>
#include <memory>
#include "../include/Painting.h"
#include "../include/Sculpture.h"

using namespace std;

std::vector<std::string> split(const std::string &line, const char delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end;

    while ((end = line.find(delimiter, start)) != std::string::npos) {
        result.push_back(line.substr(start, end - start));
        start = end + 1;
    }

    result.push_back(line.substr(start)); // last piece

    return result;
}

vector<unique_ptr<Artwork> > loadData(const string &filename) {
    vector<unique_ptr<Artwork> > artworks;
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open " << filename << endl;
        return artworks;
    }

    string line;
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');

        if (fields.empty()) continue;

        if (fields[0] == "Painting") {
            artworks.push_back(make_unique<Painting>(createPainting(fields)));
        } else if (fields[0] == "Sculpture") {
            artworks.push_back(make_unique<Sculpture>(createSculpture(fields)));
        }else {
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

    return 0;
}
