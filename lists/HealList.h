#pragma once

#include "../structures/ArrayStack.h"
#include "../units/EarthHeal.h"

class HealList {
private:
    ArrayStack<EarthHeal*> stack;

public:
    bool add(EarthHeal* unit);
    bool remove(EarthHeal*& unit);
    void print();

    int getCount() const;
};