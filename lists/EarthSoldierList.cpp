#include "EarthSoldierList.h"

bool EarthSoldierList::add(EarthSoldier* unit) { 
    if (!unit) return false;
    return queue.enqueue(unit); }

bool EarthSoldierList::remove(EarthSoldier*& unit) {
    return queue.dequeue(unit);
}

void EarthSoldierList::print() {
    int count = queue.getCount();
    cout << count << " ES ";
    queue.print();
}

int EarthSoldierList::getCount() const {
    return queue.getCount();
}