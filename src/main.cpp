#include <iostream>
#include <fstream>
#include <memory>
#include "../include/Utility.h"

using namespace std;

int main() {
    const string mainCollectionFile = "../data/artworks.csv";
    const string userCollectionFile = "../data/userCollection.csv";
// museumEnterance();
    museumLogo();
    cout << "Welcome to the Museum Management System (MMS)! \nAttempting to Load artworks from artworks.csv" << endl;

    // Load the main collection of artworks from a CSV file
    // The loadData function returns a vector of shared pointers to Artwork objects
    const vector<shared_ptr<Artwork> > main_collection = loadData(mainCollectionFile);

    // If loading fails, generate sample artworks (pre-set)
    if (main_collection.empty()) {
        cout << "Error loading file or no artworks found. Loading pre-set artworks" << endl;
        generateSampleArtworks();
    } else {
        cout << "Successfully loaded artworks!\n" << endl;
    }

    // Load the user's collection (using the same format, shared pointers)
    vector<shared_ptr<Artwork> > userCollection = loadData(userCollectionFile);

    // Vectors to partition the artworks into different types
    vector<shared_ptr<Painting> > paintings;
    vector<shared_ptr<Sculpture> > sculptures;
    vector<shared_ptr<WrittenWord> > writtenWords;
    partitionArtworks(main_collection, paintings, sculptures, writtenWords);

    // Print the total number of items in each category and overall
    const int totalItems = Painting::numberOfPaintings + Sculpture::numberOfSculptures +
                           WrittenWord::numberOfWrittenWordItems;
    cout << "Total paintings = " << Painting::numberOfPaintings << endl;
    cout << "Total sculptures = " << Sculpture::numberOfSculptures << endl;
    cout << "Total written word items = " << WrittenWord::numberOfWrittenWordItems << endl;
    cout << "Total items= " << totalItems << endl;
    cout << endl;

    // Main loop for user interaction
    int input;
    while (true) {
        cout << "Options:\n"
                << "1. Select Exhibit\n"
                << "2. View Artwork list\n"
                << "3. Edit your collection\n"
                << "4. View your collection\n"
                << "5. Most valuable artwork\n"
                << "6. Least valuable artwork\n"
                << "7. Exit\n";
        cout << "Please enter your choice (1-7): ";

        // Check user input for valid selection
        if (!getInput(input) || input < 1 || input > 7) {
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
                cout << "Please enter your choice (1-4): ";
                if (!getInput(exhibitChoice) || exhibitChoice < 1 || exhibitChoice > 4) {
                    cout << "Invalid selection. Plea1se try again.\n";
                    continue;
                }
                switch (exhibitChoice) {
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
                break;
            }

            case 2:
                // Option to view the entire list of artwork titles
                cout << "Viewing the full artwork list...\n";
                printCollectionTitles(main_collection);
                break;

            case 3:
                // Option to add artworks to the user's collection
                addToUserCollection(main_collection, userCollection);
                break;

            case 4:
                // Option to view the user's collection
                if (!userCollection.empty())
                    printCollectionStrings(userCollection);
                else
                    cout << "Your collection is currently empty\n" << endl;
                break;

            case 5: {
                // Option to find and display the most valuable artwork in the main collection
                if (const Artwork *maxValueItem = findMaxValue<Artwork>(main_collection)) {
                    cout << "Most valuable artwork:\n" << maxValueItem->toString() << "\n\n";
                } else {
                    cout << "No artworks available.\n";
                }
                break;
            }

            case 6: {
                // Option to find and display the least valuable artwork in the main collection
                if (const Artwork *minValueItem = findMinValue<Artwork>(main_collection)) {
                    cout << "Least valuable artwork:\n" << minValueItem->toString() << "\n\n";
                } else {
                    cout << "No artworks available.\n\n";
                }
                break;
            }

            case 7:
                // Exiting the program and saving the user's collection to a CSV file
                cout << "Exiting program.\n";
                writeCollectionToCSV(userCollection, userCollectionFile);
                return 0;

            default:
                // This case should never be reached due to the input validation earlier
                cout << "Invalid selection. Please try again.\n\n";
                break;
        }
    }
}
