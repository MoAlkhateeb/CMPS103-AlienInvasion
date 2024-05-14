#include "AlienDroneList.h"

bool AlienDroneList::add(AlienDrone* unit1, AlienDrone* unit2) {
    bool added = false;
    if (unit1) {
        deque.enqueueFront(unit1);
        added = true;
    }

    if (unit2) {
        deque.enqueue(unit2);
        added = true;
    }
    return added;
}

bool AlienDroneList::remove(AlienDrone*& unit1, AlienDrone*& unit2) {
    if (deque.getCount() < 2) return false;
    deque.dequeue(unit1);
    deque.dequeueBack(unit2);
    return true;
}

void AlienDroneList::print() {
    int count = deque.getCount();
    cout << count << " AD ";
    deque.print();
}


int AlienDroneList::getCount() const {
    return deque.getCount();
}