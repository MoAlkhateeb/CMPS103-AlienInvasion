#pragma once

#include "../structures/ArrayBag.h"
#include "../units/AlienMonster.h"

class AlienMonsterList {
   private:
    ArrayBag<AlienMonster*> bag;

   public:
    bool add(AlienMonster* unit) { return bag.add(unit); }

    bool remove(AlienMonster*& unit) { return bag.removeRandom(unit); }

    void print() {
        int count = bag.getCount();
        cout << count << " AM ";
        bag.print();
    }
};