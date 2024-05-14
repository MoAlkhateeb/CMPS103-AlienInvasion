#include "HealList.h"

bool HealList::add(Unit* unit) {
    if (!unit) return false;
    return stack.push(unit);
}

bool HealList::remove(Unit*& unit) { return stack.pop(unit); }

void HealList::print() {
    int count = stack.getCount();
    cout << "============== Heal List ==============" << endl;
    cout << count << ((count == 1) ? " unit " : " units ");
    stack.print();
}