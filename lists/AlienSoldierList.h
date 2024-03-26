#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/AlienSoldier.h"

class AlienSoldierList {
   private:
    LinkedQueue<AlienSoldier*> queue;

   public:
    bool add(AlienSoldier* unit) { return queue.enqueue(unit); }

    bool remove(AlienSoldier*& unit) { return queue.dequeue(unit); }

    void print() {
        int count = queue.getCount();
        cout << count << " AS ";
        queue.print();
    }
};