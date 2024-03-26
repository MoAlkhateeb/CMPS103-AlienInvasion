#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/Unit.h"

class KilledList {
   private:
    LinkedQueue<Unit*> queue;

   public:
    bool add(Unit* unit) { return queue.enqueue(unit); }

    bool remove(Unit*& unit) { return queue.dequeue(unit); }

    void print() {
        int count = queue.getCount();
        cout << "============== Killed/Destructed Units ==============" << endl;
        cout << count << ((count == 1) ? " unit " : " units ");
        queue.print();
    }
};