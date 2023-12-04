//
// Created by Leila Ossi.
//

#ifndef FOODRECORD_H
#define FOODRECORD_H

#include <string>
#include <vector>

struct FoodRecord {
public:
    FoodRecord(std::string NDB_No, std::string shrt_Desc, int energ_Kcal, double protein, int calcium,
               double sugarTotal, int potassium, int sodium, int cholestrl, double lipidTotal,
               double gmwt1, std::string gmwt_Desc1, double gmwt2, std::string gmwt_Desc2);

    void display();

    std::string nDB_No;
    std::string Shrt_Desc;
    int Energ_Kcal;
    double Protein;
    int Calcium;
    double SugarTotal;
    int Potassium;
    int Sodium;
    int Cholestrl;
    double LipidTotal;
    double Gmwt1;
    std::string Gmwt_Desc1;
    double Gmwt2;
    std::string Gmwt_Desc2;
    std::vector<std::string> names;

};

#endif // FOODRECORD_H
