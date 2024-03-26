#include "AlienArmy.h"

#include <iostream>

bool AlienArmy::addUnit(Unit* unit1, Unit* unit2 = nullptr) {
    if (!unit2) {
        switch (unit1->getType()) {
            case A_SOLDIER:
                SoldierList.add(dynamic_cast<AlienSoldier*>(unit1));
                break;
            case A_MONSTER:
                MonsterList.add(dynamic_cast<AlienMonster*>(unit1));
                break;
        }
    } else if (unit1->getType() == A_DRONE && unit2->getType() == A_DRONE) {
        DroneList.add(dynamic_cast<AlienDrone*>(unit1),
                      dynamic_cast<AlienDrone*>(unit1));
    }
}
void AlienArmy::print() {
    cout << "============= Alien Army Alive Units =============" << endl;
    SoldierList.print();
    MonsterList.print();
    DroneList.print();
}
bool AlienArmy::attack() {}
