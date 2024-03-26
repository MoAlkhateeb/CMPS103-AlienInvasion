#pragma once

#include "../structures/ArrayStack.h"
#include "../units/EarthTank.h"

class EarthTankList {
   private:
    ArrayStack<EarthTank*> stack;

   public:
    bool add(EarthTank* unit) { return stack.push(unit); }

    bool remove(EarthTank*& unit) { return stack.pop(unit); }

    void print() {
        int count = stack.getCount();
        cout << count << " ET ";
        stack.print();
    }
};