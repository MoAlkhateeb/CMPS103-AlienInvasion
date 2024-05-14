#include "EarthSoldierMaintainList.h"

bool EarthSoldierMaintainList::add(EarthSoldier* unit) {
    if (!unit) return false;
    priQueue.enqueue(unit, unit->getHealth());
    return true;
}

bool EarthSoldierMaintainList::remove(EarthSoldier*& unit) {
    int pri;
    return priQueue.dequeue(unit, pri);
}

void EarthSoldierMaintainList::print() {
    int count = priQueue.getCount();
    cout << "============== Earth Soldier Maintain List ==============" << endl;
    cout << count << ((count == 1) ? " unit " : " units ");
    priQueue.print();
}

int EarthSoldierMaintainList::getCount() const {
    return priQueue.getCount();
}