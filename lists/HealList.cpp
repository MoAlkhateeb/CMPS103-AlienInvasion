#include "HealList.h"

bool HealList::add(EarthHeal* unit) {
    if (!unit) return false;
    return stack.push(unit);
}

bool HealList::remove(EarthHeal*& unit) { return stack.pop(unit); }

void HealList::print() {
    int count = stack.getCount();
    cout << "============== Heal List ==============" << endl;
    cout << count << ((count == 1) ? " unit " : " units ");
    stack.print();
}

int HealList::getCount() const {
    return stack.getCount();
}