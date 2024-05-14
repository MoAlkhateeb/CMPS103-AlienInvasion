#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/EarthSoldier.h"

class EarthSoldierList {
   private:
    LinkedQueue<EarthSoldier*> queue;

   public:
    bool add(EarthSoldier* unit);
    bool remove(EarthSoldier*& unit);
    void print();
};
