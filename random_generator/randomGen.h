#pragma once

#include <random>

#include "../units/Unit.h"

using namespace std;

typedef struct range {
    int start, end;

    range(int s = 0, int e = 0) { start = s; end = e; }
} range;

class RandGen {
   private:
    Game* game;

    int N;
    int ESPercent, ETPercent, EGPercent;
    int ASPercent, AMPercent, ADPercent;

    int HUPercent;

    int generateProb;
    range EPower, EHealth, EAttack;
    range APower, AHealth, AAttack;
    
    mt19937 gen;
    random_device rd;
    uniform_int_distribution<> Prob;

    Unit* generateRandomEarthUnit(int timeStep);
    Unit* generateRandomAlienUnit(int timeStep);

    Unit* generateUnit(int ID, int timeStep, int power, int health,
                       int capacity, UnitType type) const;

   public:
    static int alienID;
    static int earthID;

    RandGen(Game* game);

    void createUnits(int timeStep);
        
    int getRandomNumber(); // gets a random number 1 to 100;

    void setN(int N);
    void setGenerateProb(int prob);

    void setESPercent(int percent);
    void setETPercent(int percent);
    void setEGPercent(int percent);

    void setHUPercent(int percent);

    void setASPercent(int percent);
    void setAMPercent(int percent);
    void setADPercent(int percent);

    void setEPower(range power);
    void setEHealth(range health);
    void setEAttack(range attack);

    void setAPower(range power);
    void setAHealth(range health);
    void setAAttack(range attack);
};