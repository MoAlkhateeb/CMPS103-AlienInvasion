#include "KilledList.h"

bool KilledList::add(Unit* unit) { 
    if (!unit) return false;
    return queue.enqueue(unit); 
}

bool KilledList::remove(Unit*& unit) { return queue.dequeue(unit); }

void KilledList::print() {
    int count = queue.getCount();
    cout << "============== Killed/Destructed Units ==============" << endl;
    cout << count << ((count == 1) ? " unit " : " units ");
    queue.print();
}

int KilledList::getCount() const {
    return queue.getCount();
}