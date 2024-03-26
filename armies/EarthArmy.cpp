#include "EarthArmy.h"

#include <iostream>

bool EarthArmy::addUnit(Unit* unit) {
    switch (unit->getType()) {
        case E_SOLDIER:
            soldierList.add(dynamic_cast<EarthSoldier*>(unit));
            break;
        case E_TANK:
            tankList.add(dynamic_cast<EarthTank*>(unit));
            break;
        case E_GUNNERY:
            gunneryList.add(dynamic_cast<EarthGunnery*>(unit));
            break;
    }
}
void EarthArmy::print() {
    cout << "============= Earth Army Alive Units =============" << endl;
    soldierList.print();
    tankList.print();
    gunneryList.print();
}

bool EarthArmy::attack() {}