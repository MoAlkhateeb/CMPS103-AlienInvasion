#pragma once

#include "../structures/PriQueue.h"
#include "../units/EarthGunnery.h"

class EarthGunneryList {
   private:
    PriQueue<EarthGunnery*> priQueue;

   public:
    bool add(EarthGunnery* unit) {
        priQueue.enqueue(unit, unit->getPriority());
        return true;
    }

    bool remove(EarthGunnery*& unit) {
        int pri;
        return priQueue.dequeue(unit, pri);
    }

    void print() {
        int count = priQueue.getCount();
        cout << count << " EG ";
        priQueue.print();
    }
};