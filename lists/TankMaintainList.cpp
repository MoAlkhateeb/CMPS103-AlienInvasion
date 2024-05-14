#include "TankMaintainList.h"

bool TankMaintainList::add(EarthTank* unit) {
    if (!unit) return false;
    return queue.enqueue(unit);
}

bool TankMaintainList::remove(EarthTank*& unit) { return queue.dequeue(unit); }

void TankMaintainList::print() {
    int count = queue.getCount();
    cout << "============== Tank Maintain List ==============" << endl;
    cout << count << ((count == 1) ? " unit " : " units ");
    queue.print();
}

int TankMaintainList::getCount() const {
    return queue.getCount();
}