#include<iostream>
#include<random>
#include<fstream>
#include<sstream>
#include "../units/unit.h"

#define MAXAProbability 100
#define MINAProbability 1
#define MAXBProbability 100
#define MINBProbability 1
#define MAXEARTHID 999
#define MINEARTHID 1
#define MAXALIENID 2999
#define MINALIENID 2000

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

bool isFileEmpty(const string &filename){
    ifstream file(filename);
    if(!file){
        cerr << "Error: file not found" << endl;
        return false;
    }
    bool isEmpty = (file.peek() == ifstream::traits_type::eof());
    file.close();
    return isEmpty;
}

bool loadParametrs(const string &filename, Parameters &params)
{
    ifstream file(filename);
    isFileEmpty(filename);
    string line;
    file >> params.N;
    file >> params.ESPercent >> params.ETPercent >> params.EGPercent;
    file >> params.ASPercent >> params.AMPercent >> params.ADPercent;
    file >> params.Prob;
    // Read ranges of Earth and Alien armies
    file >> params.EPower.start >> params.EPower.end >> params.EHealth.start >> params.EHealth.end >> params.EAttack.start >> params.EAttack.end;
    file >> params.APower.start >> params.APower.end >> params.AHealth.start >> params.AHealth.end >> params.AAttack.start >> params.AAttack.end;
    file.close();
}

void generateUnit(Parameters &params){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> ProbA(MINAProbability, MAXAProbability);
    uniform_int_distribution<> ProbB(MINBProbability, MAXBProbability);
// Random number generator for Earth units
    uniform_int_distribution<> earthUnits(MINEARTHID, MAXEARTHID);
    uniform_int_distribution<> unitEarthPower(params.EHealth.start, abs(params.EHealth.end));
    uniform_int_distribution<> unitEarthHealth(params.EPower.start,abs(params.EPower.end));
    uniform_int_distribution<> unitEarthACap(params.EAttack.start, abs(params.EAttack.end));
// Random number generator for Alien units
    uniform_int_distribution<> alienUnits(MINALIENID, MAXALIENID);
    uniform_int_distribution<> unitAlienPower(params.AHealth.start, abs(params.AHealth.end));
    uniform_int_distribution<> unitAlienHealth(params.APower.start, abs(params.APower.end));
    uniform_int_distribution<> unitAlienACap(params.AAttack.start, abs(params.AAttack.end));
    for (int i = 0; i < params.N; i++){
        int A = ProbA(gen);
        if(A<= params.Prob){
            int B = ProbB(gen);
// Random number generated for Earth units
            int unitEID = earthUnits(gen);
            int unitEPower = unitEarthPower(gen);
            int unitEHealth = unitEarthHealth(gen);
            int unitEACap = unitEarthACap(gen);
// Radoom number generated for Alien units
            int unitAID = alienUnits(gen);
            int unitAPower = unitAlienPower(gen);
            int unitAHealth = unitAlienHealth(gen);
            int unitAACap = unitAlienACap(gen);
        }  
    }
}


