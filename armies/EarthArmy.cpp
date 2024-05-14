#include "EarthArmy.h"
#include <iostream>

bool EarthArmy::addUnit(Unit* unit) {
    if (!unit) return false;
    switch (unit->getType()) {
        case E_SOLDIER:
            return soldierList.add(dynamic_cast<EarthSoldier*>(unit));
        case E_TANK:
            return tankList.add(dynamic_cast<EarthTank*>(unit));
        case E_GUNNERY:
            return gunneryList.add(dynamic_cast<EarthGunnery*>(unit));
        default:
            return false;
    }
}
void EarthArmy::print() {
    cout << "============= Earth Army Alive Units =============" << endl;
    soldierList.print();
    tankList.print();
    gunneryList.print();
}

EarthSoldierList* EarthArmy::getESList() { return &soldierList;  }
EarthTankList* EarthArmy::getETList() { return &tankList;}
EarthGunneryList* EarthArmy::getEGList() { return &gunneryList;  }


bool EarthArmy::attack(int timeStep, Mode operation) {

    if (!soldierList.getCount() && !tankList.getCount() && !gunneryList.getCount()) {
        return false;
    }

    EarthSoldier* ES;
    EarthTank* ET;
    EarthGunnery* EG;

    if (soldierList.remove(ES)) {
        ES->attack(timeStep, operation);
        soldierList.add(ES);
    }
    
    if (tankList.remove(ET)) {
        ET->attack(timeStep, operation);
        tankList.add(ET);
    }
    if (gunneryList.remove(EG)) {
        EG->attack(timeStep, operation);
        gunneryList.add(EG);
    }

    return true;
}

int EarthArmy::getCount() const {
    return soldierList.getCount() + tankList.getCount() + gunneryList.getCount();
}