#include <iostream>
#include <fstream>
#include <memory>
#include "../include/Utility.h"

using namespace std;


int main() {
    const string filename = "../data/artworks.csv";

    cout << "Welcome to the Museum Management System (MMS)! \nAttempting to Load artworks from artworks.csv" << endl;

    const vector<unique_ptr<Artwork> > artworks = loadData(filename);

    if (artworks.empty()) {
        cout << "Error loading file or no artworks found. Loading pre-set artworks" << endl;
        generateSampleArtworks();
    } else {
        cout << "Successfully loaded artworks!\n" << endl;
    }


    constexpr vector<unique_ptr<Artwork> > user_collection;
    vector<unique_ptr<Painting> > paintings;
    vector<unique_ptr<Sculpture> > sculptures;
    vector<unique_ptr<WrittenWord> > writtenWords;
    partitionArtworks(artworks, paintings, sculptures, writtenWords);

    const int totalItems = Painting::numberOfPaintings + Sculpture::numberOfSculptures +
                           WrittenWord::numberOfWrittenWordItems;
    cout << "Total paintings = " << Painting::numberOfPaintings << endl;
    cout << "Total sculptures = " << Sculpture::numberOfSculptures << endl;
    cout << "Total written word items = " << WrittenWord::numberOfWrittenWordItems << endl;
    cout << "Total items= " << totalItems << endl;
    cout << endl;

    int input;
    while (true) {
        cout << "Options:\n"
                << "1. Select Exhibit\n"
                << "2. View Artwork list\n"
                << "3. Create a collection\n"
                << "4. Most valuable artwork\n"
                << "5. Least valuable artwork\n"
                << "6. Exit\n";
        cout << "Please enter your choice (1-4): ";

        if (!getInput(input) || input < 1 || input > 6) {
            cout << "Invalid selection. Please try again.\n";
            continue;
        }
        switch (input) {
            case 1: {
                int exhibitChoice;
                cout << "Select Exhibit Type:\n"
                        << "1. Paintings\n"
                        << "2. Sculptures\n"
                        << "3. Written Word\n"
                        << "4. Return to Main Menu\n";
                if (!getInput(exhibitChoice) || exhibitChoice < 1 || exhibitChoice > 4) {
                    cout << "Invalid selection. Please try again.\n";
                    continue;
                }
                switch (input) {
                    case 1:
                        cout << "You selected Paintings.\n";
                        printCollectionStrings(paintings);
                        break;
                    case 2:
                        cout << "You selected Sculptures.\n";
                        printCollectionStrings(sculptures);
                        break;
                    case 3:
                        cout << "You selected Written Word.\n";
                        printCollectionStrings(writtenWords);
                        break;
                    case 4:
                        cout << "Returning to main menu...\n";
                        break;
                    default:
                        cout << "Invalid selection. Please Try again\n";
                        break;
                }
            }

            case 2:
                cout << "Viewing the full artwork list...\n";
                printCollectionTitles(artworks);
                break;

            case 3:
                cout << "Create a new collection functionality here...\n";
            // Add your collection creation logic here
                break;

            case 4: {
                if (const Artwork *maxValueItem = findMaxValue<Artwork>(artworks)) {
                    cout << "Most valuable artwork:\n" << maxValueItem->toString() << "\n\n";
                } else {
                    cout << "No artworks available.\n";
                }
                break;
            }

            case 5: {
                if (const Artwork *minValueItem = findMinValue<Artwork>(artworks)) {
                    cout << "Least valuable artwork:\n" << minValueItem->toString() << "\n\n";
                } else {
                    cout << "No artworks available.\n\n";
                }
                break;
            }

            case 6:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid selection. Please try again.\n\n";
                break;
        }
    }
}
