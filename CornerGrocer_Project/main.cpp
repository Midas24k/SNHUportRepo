#include "GroceryTracker.h"

#include <iostream>

using namespace std;

int main() {
    GroceryTracker groceryTracker("CS210_Project_Three_Input_File.txt");

    // Load the input file before showing the menu so all options use current data.
    if (!groceryTracker.loadItems()) {
        return 1;
    }

    // Create the required backup file at the beginning of the program.
    if (!groceryTracker.createBackupFile()) {
        return 1;
    }

    cout << "Corner Grocer Item Tracking Program" << endl;
    cout << "Data loaded successfully. Backup file frequency.dat created." << endl << endl;

    groceryTracker.runMenu();

    return 0;
}
