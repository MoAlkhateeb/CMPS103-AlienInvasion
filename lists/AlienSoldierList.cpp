#include "AlienSoldierList.h"

bool AlienSoldierList::add(AlienSoldier* unit) { 
    if (!unit) return false;
    return queue.enqueue(unit); 
}

bool AlienSoldierList::remove(AlienSoldier*& unit) {
    return queue.dequeue(unit);
}

void AlienSoldierList::print() {
    int count = queue.getCount();
    cout << count << " AS ";
    queue.print();
}

int AlienSoldierList::getCount() const {
    return queue.getCount();
}