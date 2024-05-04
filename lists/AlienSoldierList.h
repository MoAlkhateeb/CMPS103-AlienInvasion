#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/AlienSoldier.h"

class AlienSoldierList {
    private:
    LinkedQueue<AlienSoldier*> queue;

    public:
    bool add(AlienSoldier* unit);
    bool remove(AlienSoldier*& unit);
    void print();
    bool isEmpty();
    int getCount();
    bool peek(AlienSoldier* unit);
};