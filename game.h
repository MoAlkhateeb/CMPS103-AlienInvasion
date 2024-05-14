
#pragma once

#include <fstream>
#include <iostream>

#include "armies/AlienArmy.h"
#include "armies/EarthArmy.h"
#include "lists/KilledList.h"
#include "lists/HealList.h"
#include "lists/TankMaintainList.h"
#include "lists/EarthSoldierMaintainList.h"
#include "random_generator/randomGen.h"

#define MAXEARTHID 999
#define MINEARTHID 1
#define MAXALIENID 2999
#define MINALIENID 2000

using namespace std;

class Game {
   private:
    int timeStep;

    AlienArmy aliens;
    EarthArmy earth;
    KilledList killed;
    HealList heal;
    TankMaintainList tankMaintain;
    EarthSoldierMaintainList soldierMaintain;
    RandGen randGen;

    bool loadParameters(const string &filename);

   public:
    Game(const string &inputFile);

    EarthArmy* getEarthArmy() const;
    AlienArmy* getAlienArmy() const;
    KilledList* getKilled() const;
    HealList* getHealList() const;
    TankMaintainList* getTankMaintainList() const;
    EarthSoldierMaintainList* getEarthSoldierMaintainList() const;

    void runInteractive();

    void print();
};
