#pragma once

#include <iostream>

#include "../lists/EarthGunneryList.h"
#include "../lists/EarthSoldierList.h"
#include "../lists/EarthTankList.h"

using namespace std;

class EarthArmy {
   private:
    EarthSoldierList soldierList;
    EarthTankList tankList;
    EarthGunneryList gunneryList;

   public:
    EarthSoldierList* getESList();
    EarthTankList* getETList();
    EarthGunneryList* getEGList();

    void print();
    bool addUnit(Unit* unit);
    bool attack();
};
