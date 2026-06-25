CS210 Project Three - Corner Grocer

Files included:
- main.cpp: Main program driver. Keeps main small and starts the menu.
- GroceryTracker.h: Class declaration with public and private sections.
- GroceryTracker.cpp: Class implementation for file input, backup file output, search, frequency list, histogram, and menu validation.
- CS210_Project_Three_Input_File.txt: Input file used by the program.
- frequency.dat: Sample/generated backup file. The program recreates this file when it runs.

How to compile with g++:
g++ -std=c++17 main.cpp GroceryTracker.cpp -o CornerGrocer

How to run:
./CornerGrocer

Visual Studio setup:
1. Create a new C++ console project.
2. Add main.cpp, GroceryTracker.h, and GroceryTracker.cpp to the project.
3. Place CS210_Project_Three_Input_File.txt in the same folder as the executable.
4. Build and run the project.

Program menu:
1. Search for an item frequency.
2. Print all item frequencies.
3. Print item histogram.
4. Exit.
