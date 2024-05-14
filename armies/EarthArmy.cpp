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


bool EarthArmy::attack() {
    EarthSoldierList *ESList = getESList();
    EarthTankList *ETList = getETList();
    EarthGunneryList *EGList = getEGList();

    if(ESList->isEmpty() || ETList->isEmpty()|| EGList->isEmpty()){
        return false;
    }
    EarthSoldier *ES = nullptr;
    EarthTank *ET = nullptr;
    EarthGunnery *EG = nullptr;

    if(ESList->remove(ES)){
        if(ETList->remove(ET)){
            if(EGList->remove(EG)){
                ES->attack();
                ET->attack();
                EG->attack();

                ESList->add(ES);
                ETList->add(ET);
                EGList->add(EG);

                return true;
            }else {
                ESList->add(ES);
                ETList->add(ET);
            }
        }else {
            ESList->add(ES);
        }
    }
    return false;
}