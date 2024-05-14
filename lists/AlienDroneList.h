#pragma once

#include "../structures/Deque.h"
#include "../units/AlienDrone.h"

class AlienDroneList {
   private:
    Deque<AlienDrone*> deque;

   public:
    bool add(AlienDrone* unit1, AlienDrone* unit2 = nullptr);
    bool remove(AlienDrone*& unit1, AlienDrone*& unit2);
    void print();

    int getCount() const;
};