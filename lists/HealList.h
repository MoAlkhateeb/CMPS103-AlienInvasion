#pragma once

#include "../structures/ArrayStack.h"
#include "../units/Unit.h"

class HealList {
private:
    ArrayStack<Unit*> stack;

public:
    bool add(Unit* unit);
    bool remove(Unit*& unit);
    void print();
};