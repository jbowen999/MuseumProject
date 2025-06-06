#include "../include/WrittenWord.h"

#include <sstream>


int WrittenWord::numberOfWrittenWordItems = 0; // Initialize the static variable

WrittenWord::WrittenWord(const string &artistFirst, const string &artistLast,
                         const string &title, const int createdMonth,
                         const int createdDay, const int createdYear,
                         const int acquiredMonth, const int acquiredDay,
                         const int acquiredYear, const string &donatedFirst,
                         const string &donatedLast, const int numPages,
                         const Medium medium, const string &description) {
    setArtist(artistFirst, artistLast);
    setTitle(title);
    setCreatedDate(createdMonth, createdDay, createdYear);
    setAcquiredDate(acquiredMonth, acquiredDay, acquiredYear);
    setDonatedBy(donatedFirst, donatedLast);
    this->numPages = numPages;
    this->medium = medium;
    setDescription(description);
    numberOfWrittenWordItems++;
}

// Helper function for toString()
string WrittenWord::getMediumAsString() const {
    switch (medium) {
        case Medium::Novel: return "Novel";
        case Medium::Biography: return "Biography";
        case Medium::Anthology: return "Anthology";
        case Medium::Illustrated: return "Illustrated";
        case Medium::Autobiography: return "Autobiography";
        case Medium::Nonfiction: return "Nonfiction";
        case Medium::Poetry: return "Poetry";
        default: return "Unknown";
    }
}
// Helper function for parsing CSV file
WrittenWord::Medium parseWrittenWordMedium(const std::string &str) {
    if (str == "Novel") return WrittenWord::Medium::Novel;
    if (str == "Biography") return WrittenWord::Medium::Biography;
    if (str == "Anthology") return WrittenWord::Medium::Anthology;
    if (str == "Illustrated") return WrittenWord::Medium::Illustrated;
    if (str == "Autobiography") return WrittenWord::Medium::Autobiography;
    if (str == "Nonfiction") return WrittenWord::Medium::Nonfiction;
    if (str == "Poetry") return WrittenWord::Medium::Poetry;
    throw std::invalid_argument("Unknown medium: " + str);
}

// Override functions
string WrittenWord::toString() const {
    return "WrittenWord: \"" + getTitle() + "\"\n"
           "Artist: " + getArtist().toString() + "\n"
           "Description: " + getDescription() + "\n"
           "Created: " + getCreatedDate().toString() + "\n"
           "Acquired: " + getAcquiredDate().toString() + "\n"
           "Donated by: " + getDonatedBy().toString() + "\n"
           "Number of Pages: " + to_string(numPages) + "\n"
           "Medium: " + getMediumAsString() + "\n"
           "Value: " + format("${:.2f}", value());
}

double WrittenWord::value() const {
    // Calculate age
    constexpr int currentYear = 2025;
    const int age = currentYear - getCreatedDate().getYear();

    // Final value
    return age * (static_cast<double>(numPages) / 100);
}

std::string WrittenWord::toCSV() const {
    std::ostringstream oss;
    oss << "WrittenWord,"
        << getTitle() << ","
        << getArtist().toCSVString() << ","
        << getCreatedDate().toCSVString() << ","
        << getAcquiredDate().toCSVString() << ","
        << getDonatedBy().toCSVString() << ","
        << to_string(numPages) << ","
        << getMediumAsString() << ","
        << getDescription() << ",";
    return oss.str();
}

// Function to create object after csv parsing
WrittenWord createWrittenWord(const vector<string> &fields) {
    const string &artistFirstName = fields[1];
    const string &artistLastName = fields[2];
    const string &title = fields[3];
    const int createdMonth = stoi(fields[4]);
    const int createdDay = stoi(fields[5]);
    const int createdYear = stoi(fields[6]);
    const int acquiredMonth = stoi(fields[7]);
    const int acquiredDay = stoi(fields[8]);
    const int acquiredYear = stoi(fields[9]);
    const string &donatedFirst = fields[10];
    const string &donatedLast = fields[11];
    const int numPages = stoi(fields[12]);
    const WrittenWord::Medium medium = parseWrittenWordMedium(fields[13]);
    const string &description = fields[14];

    return WrittenWord(
        artistFirstName, artistLastName,
        title,
        createdMonth, createdDay, createdYear,
        acquiredMonth, acquiredDay, acquiredYear,
        donatedFirst, donatedLast,
        numPages,
        medium, description
    );
}
