#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/EarthSoldier.h"

class EarthSoldierList {
   private:
    LinkedQueue<EarthSoldier*> queue;

   public:
    bool add(EarthSoldier* unit) { return queue.enqueue(unit); }

    bool remove(EarthSoldier*& unit) { return queue.dequeue(unit); }

    void print() {
        int count = queue.getCount();
        cout << count << " ES ";
        queue.print();
    }
};