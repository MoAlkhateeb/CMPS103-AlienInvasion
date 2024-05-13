#pragma once

#include "../structures/ArrayStack.h"
#include "../units/EarthTank.h"

class EarthTankList {
   private:
    ArrayStack<EarthTank*> stack;

   public:
    bool add(EarthTank* unit);
    bool remove(EarthTank*& unit);
    void print();
    
};