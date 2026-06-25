#include "GroceryTracker.h"

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

GroceryTracker::GroceryTracker(const string& inputFileName, const string& backupFileName) {
    this->inputFileName = inputFileName;
    this->backupFileName = backupFileName;
}

string GroceryTracker::formatItemName(const string& itemName) {
    string formattedName;

    // Keep alphabetic characters and ignore accidental punctuation or spaces.
    for (char character : itemName) {
        if (isalpha(static_cast<unsigned char>(character))) {
            formattedName += static_cast<char>(tolower(static_cast<unsigned char>(character)));
        }
    }

    if (!formattedName.empty()) {
        formattedName.at(0) = static_cast<char>(toupper(static_cast<unsigned char>(formattedName.at(0))));
    }

    return formattedName;
}

bool GroceryTracker::loadItems() {
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open input file: " << inputFileName << endl;
        return false;
    }

    string itemName;

    // Read each item from the file and count how often it appears.
    while (inputFile >> itemName) {
        itemName = formatItemName(itemName);

        if (!itemName.empty()) {
            ++itemFrequencies[itemName];
        }
    }

    inputFile.close();
    return true;
}

bool GroceryTracker::createBackupFile() const {
    ofstream outputFile(backupFileName);

    if (!outputFile.is_open()) {
        cout << "Error: Unable to create backup file: " << backupFileName << endl;
        return false;
    }

    // Back up every item and its accumulated frequency count.
    for (const auto& item : itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
    return true;
}

int GroceryTracker::getItemFrequency(const string& itemName) const {
    string formattedName = formatItemName(itemName);
    auto itemIterator = itemFrequencies.find(formattedName);

    if (itemIterator == itemFrequencies.end()) {
        return 0;
    }

    return itemIterator->second;
}

void GroceryTracker::printFrequencies() const {
    cout << endl << "Item Purchase Frequencies" << endl;
    cout << "-------------------------" << endl;

    for (const auto& item : itemFrequencies) {
        cout << left << setw(15) << item.first << item.second << endl;
    }

    cout << endl;
}

void GroceryTracker::printHistogram() const {
    cout << endl << "Item Purchase Histogram" << endl;
    cout << "-----------------------" << endl;

    for (const auto& item : itemFrequencies) {
        cout << left << setw(15) << item.first << string(item.second, '*') << endl;
    }

    cout << endl;
}

void GroceryTracker::displayMenu() const {
    cout << "==============================" << endl;
    cout << " Corner Grocer Tracking Menu" << endl;
    cout << "==============================" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print item histogram" << endl;
    cout << "4. Exit" << endl;
}

int GroceryTracker::getValidatedMenuChoice() {
    int userChoice;

    while (true) {
        cout << "Enter your choice (1-4): ";

        if (cin >> userChoice && userChoice >= 1 && userChoice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return userChoice;
        }

        cout << "Invalid choice. Please enter a number from 1 to 4." << endl << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void GroceryTracker::runMenu() const {
    bool keepRunning = true;

    while (keepRunning) {
        displayMenu();
        int userChoice = getValidatedMenuChoice();

        switch (userChoice) {
        case 1: {
            string itemName;
            cout << "Enter the item name to search for: ";
            cin >> itemName;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << formatItemName(itemName) << " was purchased "
                 << getItemFrequency(itemName) << " time(s)." << endl << endl;
            break;
        }
        case 2:
            printFrequencies();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            keepRunning = false;
            break;
        default:
            // This default is included for safety, although validation prevents it.
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
