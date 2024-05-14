#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/Unit.h"

class KilledList {
   private:
    LinkedQueue<Unit*> queue;

   public:
    bool add(Unit* unit);
    bool remove(Unit*& unit);
    void print();

    int getCount() const;
};