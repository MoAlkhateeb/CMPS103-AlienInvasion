#include "EarthGunneryList.h"

bool EarthGunneryList::add(EarthGunnery* unit) {
    if (!unit) return false;
    priQueue.enqueue(unit, unit->getPriority());
    return true;
}

bool EarthGunneryList::remove(EarthGunnery*& unit) {
    int pri;
    return priQueue.dequeue(unit, pri);
}

void EarthGunneryList::print() {
    int count = priQueue.getCount();
    cout << count << " EG ";
    priQueue.print();
}

int EarthGunneryList::getCount() const {
    return priQueue.getCount();
}