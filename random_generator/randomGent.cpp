#include<iostream>
#include<random>
#include<vector>
#include<fstream>
#include<sstream>
#include "../CMPS103-AlienInvasion/units/unit.h"
using namespace std;
typedef struct range {
    int start, end;
} range;
struct Parameters 
{
    int N;
    int ESPercent, ETPercent, EGPercent;
    int ASPercent, AMPercent, ADPercent;
    int Prob;
    range EPower, EHealth, EAttack;
    range APower,AHealth, AAttack;
};

bool isblank(string &line)
{
    return line.find_first_not_of(" \t") == string::npos;
}
void loadParametrs(const string &filename, Parameters &params)
{
    ifstream file(filename);
    if(!file.is_open()){
        cerr << "Error: file not found" << endl;
        return;
    }
    file >> params.N;
    file >> params.ESPercent >> params.ETPercent>> params.EGPercent;
    file >> params.ASPercent >> params.AMPercent >> params.ADPercent;
    file >> params.Prob;
    // Read ranges of Earth and Alien armies
    file >> params.EPower.start >> params.EPower.end >> params.EHealth.start >> params.EHealth.end >> params.EAttack.start >> params.EAttack.end;
    char hyphen;
    file >> params.APower.start  >> params.APower.end >> params.AHealth.start >>params.AHealth.end >> params.AAttack.start >> params.AAttack.end;
    file.close();
}
void generateUnit(Parameters &params){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
// Random number generator for Earth units
    uniform_int_distribution<> earthUnits(1, 999);
    uniform_int_distribution<> unitEarthPower(params.EHealth.start, abs(params.EHealth.end));
    uniform_int_distribution<> unitEarthHealth(params.EPower.start,abs(params.EPower.end));
    uniform_int_distribution<> unitEarthACap(params.EAttack.start, abs(params.EAttack.end));
// Random number generator for Alien units
    uniform_int_distribution<> alienUnits(2000, 2999);
    uniform_int_distribution<> unitAlienPower(params.AHealth.start, abs(params.AHealth.end));
    uniform_int_distribution<> unitAlienHealth(params.APower.start, abs(params.APower.end));
    uniform_int_distribution<> unitAlienACap(params.AAttack.start, abs(params.AAttack.end));
    // cout << abs(params.EHealth.end) << endl;
    for (int i = 0; i < params.N; i++)
    {
        // cout<<params.N<<endl;
        int A = dis(gen);
        if(A<= params.Prob){
            int B = dis(gen);
// Random number generated for Earth units
            int unitEID = earthUnits(gen);
            int unitEPower = unitEarthPower(gen);
            int unitEHealth = unitEarthHealth(gen);
            int unitEACap = unitEarthACap(gen);
            cout << unitEID << " " << unitEPower << " " << unitEHealth << " " << unitEACap << endl;
// Radoom number generated for Alien units
            int unitAID = alienUnits(gen);
            int unitAPower = unitAlienPower(gen);
            int unitAHealth = unitAlienHealth(gen);
            int unitAACap = unitAlienACap(gen);
            cout << unitAID << " " << unitAPower << " " << unitAHealth << " " << unitAACap << endl;
        }else {
            cout << "An iteration is missed \n";
            continue;
        }   
    }
    // cout << random << endl;
}
int main(){
    Parameters params;
    loadParametrs("input.txt", params);
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

