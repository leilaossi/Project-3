//
// Created by Leila Ossi.
//

#include "foodrecord.h"
#include <iostream>

FoodRecord::FoodRecord(std::string NDB_No, std::string shrt_Desc, int energ_Kcal, double protein, int calcium,
                       double sugarTotal, int potassium, int sodium, int cholestrl, double lipidTotal,
                       double gmwt1, std::string gmwt_Desc1, double gmwt2, std::string gmwt_Desc2) {
    nDB_No = NDB_No;
    Shrt_Desc = shrt_Desc;
    Energ_Kcal = energ_Kcal;
    Protein = protein;
    Calcium = calcium;
    SugarTotal = sugarTotal;
    Potassium = potassium;
    Sodium = sodium;
    Cholestrl = cholestrl;
    LipidTotal = lipidTotal;
    Gmwt1 = gmwt1;
    Gmwt_Desc1 = gmwt_Desc1;
    Gmwt2 = gmwt2;
    Gmwt_Desc2 = gmwt_Desc2;

}

void FoodRecord::display() {
    std::cout << " Food Number: " << nDB_No << std::endl;
    std::cout << " Food Title: " << Shrt_Desc << std::endl;
    std::cout << " Calories (kcal/100g): " << Energ_Kcal << std::endl;
    std::cout << " Protein (g/100g): " << Protein << std::endl;
    std::cout << " Calcium (mg/100g): " << Calcium << std::endl;
    std::cout << " Total Sugar (g/100g): " << SugarTotal << std::endl;
    std::cout << " Potassium (mg/100g): " << Potassium << std::endl;
    std::cout << " Sodium (mg/100g): " << Sodium << std::endl;
    std::cout << " Cholesterol (mg/100g): " << Cholestrl << std::endl;
    std::cout << " Total Lipid (fat)(g/100g): " << LipidTotal << std::endl;
    std::cout << " Gram Weight 1: " << Gmwt1 << std::endl;
    std::cout << " Gram Weight 1 Description: " << Gmwt_Desc1 << std::endl;
    std::cout << " Gram Weight 2: " << Gmwt2 << std::endl;
    std::cout << " Gram Weight 2 Description: " << Gmwt_Desc2 << std::endl;
    std::cout << std::endl;

}

