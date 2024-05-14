#pragma once

#include "../structures/PriQueue.h"
#include "../units/EarthGunnery.h"

class EarthGunneryList {
   private:
    PriQueue<EarthGunnery*> priQueue;

   public:
    bool add(EarthGunnery* unit);
    bool remove(EarthGunnery*& unit);
    void print();

    int getCount() const;
};