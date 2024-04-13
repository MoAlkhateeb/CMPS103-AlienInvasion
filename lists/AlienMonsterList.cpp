#include "AlienMonsterList.h"

bool AlienMonsterList::add(AlienMonster* unit) { 
    if (!unit) return false;
    return bag.add(unit); 
}

bool AlienMonsterList::remove(AlienMonster*& unit) {
    return bag.removeRandom(unit);
}

void AlienMonsterList::print() {
    int count = bag.getCount();
    cout << count << " AM ";
    bag.print();
}
