#pragma once

#include "../structures/Deque.h"
#include "../units/AlienDrone.h"

class AlienDroneList {
   private:
    Deque<AlienDrone*> deque;

   public:
    bool add(AlienDrone* unit1, AlienDrone* unit2) {
        deque.enqueueFront(unit1);
        deque.enqueue(unit2);
        return true;
    }

    bool remove(AlienDrone*& unit1, AlienDrone*& unit2) {
        if (deque.getCount() < 2) return false;
        deque.dequeue(unit1);
        deque.dequeueBack(unit2);
        return true;
    }

    void print() {
        int count = deque.getCount();
        cout << count << " AD ";
        deque.print();
    }
};