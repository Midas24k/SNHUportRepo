#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

// GroceryTracker handles all file input, frequency counting, and menu output
// for the Corner Grocer item-tracking program.
class GroceryTracker {
public:
    // Constructor stores the input and backup file names for this tracker.
    explicit GroceryTracker(const std::string& inputFileName,
                            const std::string& backupFileName = "frequency.dat");

    // Reads grocery item records from the input file and counts each item.
    bool loadItems();

    // Writes the counted item frequencies to frequency.dat for backup purposes.
    bool createBackupFile() const;

    // Returns the number of times a specific item appears in the input file.
    int getItemFrequency(const std::string& itemName) const;

    // Prints every item with its numeric purchase frequency.
    void printFrequencies() const;

    // Prints every item with a histogram made of asterisks.
    void printHistogram() const;

    // Runs the menu loop until the user chooses to exit.
    void runMenu() const;

private:
    std::map<std::string, int> itemFrequencies;
    std::string inputFileName;
    std::string backupFileName;

    // Formats an item name so user searches are not case-sensitive.
    static std::string formatItemName(const std::string& itemName);

    // Displays the menu choices to the user.
    void displayMenu() const;

    // Gets and validates a menu choice between 1 and 4.
    static int getValidatedMenuChoice();
};

#endif
