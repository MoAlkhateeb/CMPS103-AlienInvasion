
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

enum Mode { INTERACTIVE = 1, SILENT };
enum WON { TBD, ALIENS, EARTH, DRAW };

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

    WON won;

    const string outputFile;
    const string inputFile;

    bool loadParameters();

   public:

    Game(const string& inputFile, const string& outputFile);

    EarthArmy* getEarthArmy() const;
    AlienArmy* getAlienArmy() const;
    KilledList* getKilled() const;
    HealList* getHealList() const;
    TankMaintainList* getTankMaintainList() const;
    EarthSoldierMaintainList* getEarthSoldierMaintainList() const;
     
    bool generateOutput();
    WON Game::checkWinCondition();

    void run(Mode operation);

    void print();
};
