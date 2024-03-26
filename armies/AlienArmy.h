#pragma once

#include <iostream>

#include "../lists/AlienDroneList.h"
#include "../lists/AlienMonsterList.h"
#include "../lists/AlienSoldierList.h"

using namespace std;

class AlienArmy {
   private:
    AlienSoldierList SoldierList;
    AlienDroneList DroneList;
    AlienMonsterList MonsterList;

   public:
    void print();
    bool addUnit(Unit* unit1, Unit* unit2 = nullptr);
    bool attack();
};
