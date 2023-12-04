/*

Leila Ossi
Project 3: CTRL+EAT+DEL
Ternary Search vs. Jump Search

SOURCES CITED:
- Food Nutritional Values shared by Chris Awram at: https://data.world/awram/food-nutritional-values
  ** used as my CSV dataset **
- Ternary Search by geeksforgeeks at: https://www.geeksforgeeks.org/ternary-search/
  ** used in my ternarySearch function **
- Jump Search by geeksforgeeks at: https://www.geeksforgeeks.org/jump-search/
  ** used in my jumpSearch function **
- fernandozamoraj / ParsingDemo.cpp at: https://gist.github.com/fernandozamoraj/aa35555a56884242041495cbb654dbe8
  ** used in my FoodRecord struct and displayCSV function **

*/

#include <iostream>
#include "utilities.h"

// Main function where the program execution starts
int main() {

    std::cout << "\nWELCOME TO CTRL+EAT+DEL! \n By the end of this program, "
            "you will be presented with a specific food item, \n"
            " along with that food's nutritional information. \nENJOY!\n" << std::endl;
    menu();
    return 0;

}
