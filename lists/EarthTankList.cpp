#include "EarthTankList.h"

bool EarthTankList::add(EarthTank* unit) { 
    if (!unit) return false;
    return stack.push(unit); }

bool EarthTankList::remove(EarthTank*& unit) { return stack.pop(unit); }

void EarthTankList::print() {
    int count = stack.getCount();
    cout << count << " ET ";
    stack.print();
}

int EarthTankList::getCount() const {
    return stack.getCount();
}