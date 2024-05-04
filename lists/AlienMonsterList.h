#pragma once

#include "../structures/ArrayBag.h"
#include "../units/AlienMonster.h"

class AlienMonsterList {
   private:
    ArrayBag<AlienMonster*> bag;

   public:
    bool add(AlienMonster* unit);
    bool remove(AlienMonster*& unit);
    void print();
    
};