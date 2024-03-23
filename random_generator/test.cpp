#include <iostream>
#include "random_generator/randomGent.cpp"

int main(){
    Parameters params;
    loadParametrs("/Users/omarelsawy/DS-Project /CMPS103-AlienInvasion/data/input.txt", params);
    // Display loaded parameters
    cout << "N: " << params.N << endl;
    cout << "Earth Army Percentages: " << params.ESPercent << "% " << params.ETPercent << "% " << params.EGPercent << "%" << endl;
    cout << "Alien Army Percentages: " << params.ASPercent << "% " << params.AMPercent << "% " << params.ADPercent << "%" << endl;
    cout << "Probability: " << params.Prob << "%" << endl;
    cout << "Earth Army Ranges: " << params.EPower.start << params.EPower.end << " " << params.EHealth.start  << params.EHealth.end << " " << params.EAttack.start << params.EAttack.end << endl;
    cout << "Alien Army Ranges: " << params.APower.start << params.APower.end << " " << params.AHealth.start  << params.AHealth.end << " " << params.AAttack.start << params.AAttack.end << endl;
    //Display generated units
    generateUnit(params);
    return 0;
}