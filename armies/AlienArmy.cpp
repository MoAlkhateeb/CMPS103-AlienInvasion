#include "AlienArmy.h"

#include <iostream>

bool AlienArmy::addUnit(Unit* unit1, Unit* unit2) {
    if (!unit2) {
        switch (unit1->getType()) {
            case A_SOLDIER:
                return soldierList.add(dynamic_cast<AlienSoldier*>(unit1));
            case A_MONSTER:
                return monsterList.add(dynamic_cast<AlienMonster*>(unit1));
            case A_DRONE:
                return droneList.add(dynamic_cast<AlienDrone*>(unit1));
            default:
                return false;
        }
    } 
    else if (unit1->getType() == A_DRONE && unit2->getType() == A_DRONE) {
        return droneList.add(dynamic_cast<AlienDrone*>(unit1),
                             dynamic_cast<AlienDrone*>(unit1));
    }
    else {
        return false;
    }
}
void AlienArmy::print() {
    cout << "============= Alien Army Alive Units =============" << endl;
    soldierList.print();
    monsterList.print();
    droneList.print();
}


AlienSoldierList* AlienArmy::getASList() { return &soldierList;  }
AlienDroneList* AlienArmy::getADList() { return &droneList;  }
AlienMonsterList* AlienArmy::getAMList() { return &monsterList;  }


bool AlienArmy::attack() { return false; }
