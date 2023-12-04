//
// Created by Leila Ossi.
//

#include "utilities.h"
#include "foodrecord.h" // Include the FoodRecord header if needed
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace chrono;

// Function to perform a ternary search on an array and return the index of the target element
int ternarySearch(std::vector<int> arr, int target) {
    // Implementation of ternary search
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) {
            return mid1; // Element found at mid1

        } else if (arr[mid2] == target) {
            return mid2; // Element found at mid2

        } else if (target < arr[mid1]) {
            right = mid1 - 1; // Search in the left third

        } else if (target > arr[mid2]) {
            left = mid2 + 1; // Search in the right third

        } else {
            left = mid1 + 1;
            right = mid2 - 1; // Search in the middle third

        }
    }

    return -1; // Element not found

}

// Function to perform a jump search on an array and return the index of the target element
int jumpSearch(std::vector<int> arr, int target) {
    // Implementation of jump search

    int n = arr.size();
    int step = sqrt(n); // Calculate the jump step size

    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; // Element not found

        }
    }

    // Linear search in the block
    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n)) {
            return -1; // Element not found

        }
    }

    if (arr[prev] == target) {
        return prev; // Element found

    }

    return -1; // Element not found

}

// Function to read food names from a CSV file and store them in a vector
std::vector<std::string> getNames() {
    // Implementation of getNames to read food names from a CSV file
    // Open the CSV file for reading
    ifstream inputFile;
    inputFile.open("ABBREV_alphaIndexed.csv");

    // Create a vector to store food names
    vector<FoodRecord> foods;
    string line = "";
    getline(inputFile, line);
    line = "";
    vector<string> names;

    // Read and process each line of the CSV
    while (getline(inputFile, line)) {

        // Variables to store data from CSV fields
        string blank;
        string NDB_No;
        string shrt_Desc;
        string tempString = "";
        stringstream inputString(line);

        // Parse the current line of CSV data into individual fields
        getline(inputString, NDB_No, ',');
        getline(inputString, blank, '"');
        getline(inputString, shrt_Desc, '"');

        // Create a string in the format 'NBD_No. shrt_Desc' and add it to the vector
        string output = NDB_No + ". " + shrt_Desc;
        names.push_back(output);

    }

    // Close the CSV file
    inputFile.close();

    // Return the vector of food names
    return names;

}

// Function to display the details of a food record from a CSV file
int displayCSV(int index) {
    // Implementation of displayCSV to display the details of a food record from a CSV file
    // Open the CSV file for reading
    ifstream inputFile;
    inputFile.open("ABBREV_alphaIndexed.csv");

    // Create a vector to store FoodRecord objects
    vector<FoodRecord> foods;

    // Read and ignore the first line (header) of the CSV file
    string line = "";
    getline(inputFile, line);
    line = "";
    string output;
    getline(inputFile, line);

    // Read and ignore lines until reaching the specified index
    for (int i = 0; i < index; i++) {
        if (getline(inputFile, line)) {
            // Continue reading and ignoring lines until the desired index is reached

        }
    }

    // Variables to store data from CSV fields
    string blank;
    string NDB_No;
    string shrt_Desc;
    int energ_Kcal;
    double protein;
    int calcium;
    double sugarTotal;
    int potassium;
    int sodium;
    int cholestrl;
    double lipidTotal;
    double gmwt1;
    string gmwt_Desc1;
    double gmwt2;
    string gmwt_Desc2;

    // Temporary string to hold CSV field data
    string tempString = "";

    // Parse the current line of CSV data into individual fields
    stringstream inputString(line);

    getline(inputString, NDB_No, ',');
    getline(inputString, blank, '"');
    getline(inputString, shrt_Desc, '"');
    getline(inputString, blank, ',');
    getline(inputString, tempString, ',');
    energ_Kcal = atoi(tempString.c_str());
    tempString = "";
    getline(inputString, tempString, ',');
    protein = atof(tempString.c_str());
    getline(inputString, tempString, ',');
    calcium = atoi(tempString.c_str());
    tempString = "";
    getline(inputString, tempString, ',');
    sugarTotal = atof(tempString.c_str());
    getline(inputString, tempString, ',');
    potassium = atoi(tempString.c_str());
    tempString = "";
    getline(inputString, tempString, ',');
    sodium = atoi(tempString.c_str());
    tempString = "";
    getline(inputString, tempString, ',');
    cholestrl = atoi(tempString.c_str());
    tempString = "";
    getline(inputString, tempString, ',');
    lipidTotal = atof(tempString.c_str());
    getline(inputString, tempString, ',');
    gmwt1 = atof(tempString.c_str());
    getline(inputString, blank, '"');
    getline(inputString, gmwt_Desc1, ',');
    getline(inputString, tempString, ',');
    gmwt2 = atof(tempString.c_str());
    getline(inputString, blank, '"');
    getline(inputString, gmwt_Desc2, ',');

    // Create a FoodRecord object using the parsed data
    FoodRecord food(NDB_No, shrt_Desc, energ_Kcal, protein, calcium, sugarTotal, potassium,
                    sodium, cholestrl, lipidTotal, gmwt1, gmwt_Desc1, gmwt2, gmwt_Desc2);

    // Display the details of the FoodRecord
    food.display();

    // Close the CSV file
    inputFile.close();

    return 0;

}

// Function to display the menu options to the user
int MenuText() {
    // Implementation of MenuText to display the menu options

    cout << "Menu: \n"
         << "  1. Print all food titles \n"
         << "  2. Print food categories \n"
         << "  3. Search by exact food title (TERNARY SEARCH) \n"
         << "  4. Search by exact food title (JUMP SEARCH) \n"
         << "  5. Quit \n"
         << "Menu Choice Number: ";

    return 0;

}

// Function to display the food categories to the user
int FoodCategories() {
    // Implementation of FoodCategories to display food categories
    cout << " Baby Food and Infant Formula Products\n"
         << " Baked Products\n"
         << " Beef Products\n"
         << " Beverages\n"
         << " Bread Products\n"
         << " Breakfast Cereals\n"
         << " Cereal Grains and Pasta\n"
         << " Dairy Products\n"
         << " Eggs\n"
         << " Fast Foods\n"
         << " Fruit and Fruit Products\n"
         << " Lamb, Veal and Game Products\n"
         << " Legumes and Legume Products\n"
         << " Meals, Entrées and Side Dishes\n"
         << " Nut and Seed Products\n"
         << " Pork Products\n"
         << " Poultry Products\n"
         << " Seafood and Shellfish Products\n"
         << " Snacks\n"
         << " Soups, Sauces and Gravies\n"
         << " Spices and Seasoning Products\n"
         << " Vegetable and Vegetable Products\n" << endl;

    return 0;

}

// Function to handle the menu-driven user interface
void menu() {
    // Implementation of the main menu function
    int menuChoice;
    MenuText();
    cin >> menuChoice;
    cout << endl;

    string foodTitle; // The food title that the user inputs

    int foodNum;

    vector<int> numbers;
    for (int i = 0; i < 8790; i++) {
        numbers.push_back(i+1);

    }

    while (true) {
        if (menuChoice == 1) {
            // If user chooses option 1, then print all food titles from the dataset
            vector<string> output = getNames();
            for (int i = 0; i < output.size()+1; i++) {
                cout << output[i] << endl;

            }

        } else if (menuChoice == 2) {
            // If user chooses option 2, print the food categories in the dataset
            FoodCategories();

        } else if (menuChoice == 3) {
            // If user chooses option 3, then print "What is the exact food number?"
            cout << "What is the exact food number? ";
            // Then search by the ternary search function,
            string csvFileName = "ABBREV_alphaIndexed.csv";

            // Validate the input
            while (!(std::cin >> foodNum) || foodNum < 0 || foodNum > 8790 || foodNum != static_cast<int>(foodNum)) {
                // Clear the input stream and ignore any remaining characters
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Prompt the user for valid input
                cout << "\nNot a food number! Try again: ";

            }
            cout << endl;

            // Record the start time
            auto startTime = std::chrono::high_resolution_clock::now();

            // Perform the ternary search
            int result = ternarySearch(numbers, foodNum);

            // Record the end time
            auto endTime = std::chrono::high_resolution_clock::now();

            // Calculate the elapsed time in milliseconds
            std::chrono::duration<double, milli> elapsed_time = endTime - startTime;

            displayCSV(result);

            // Print the result and elapsed time
            cout << "Ternary Search Elapsed time: " << elapsed_time.count() << " milliseconds" << endl;

            cout << endl;

        } else if (menuChoice == 4) {
            // If user chooses option 4, then print "What is the exact food number?"
            cout << "What is the exact food number? ";
            // Then search by the jump search function,
            string filename = "ABBREV_alphaIndexed.csv";

            // Validate the input
            while (!(std::cin >> foodNum) || foodNum < 0 || foodNum > 8790 || foodNum != static_cast<int>(foodNum)) {
                // Clear the input stream and ignore any remaining characters
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Prompt the user for valid input
                cout << "\nNot a food number! Try again: ";

            }
            cout << endl;

            // Start measuring time
            auto start_time = std::chrono::high_resolution_clock::now();

            // Perform the jump search
            int result = jumpSearch(numbers, foodNum);

            // Stop measuring time
            auto end_time = std::chrono::high_resolution_clock::now();

            // Calculate the elapsed time in milliseconds
            std::chrono::duration<double, milli> elapsed_time = end_time - start_time;

            displayCSV(result);

            cout << "Jump Search Elapsed time: " << elapsed_time.count() << " milliseconds.\n" << endl;

            cout << endl;

        } else if (menuChoice == 5) {
            // If user chooses option 5, then quit the program
            cout << "BYE, EAT WELL & STAY HEALTHY!\n";
            break;

        }

        MenuText();
        cin >> menuChoice;
        cout << endl;

    }
}

