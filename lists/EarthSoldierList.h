#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/EarthSoldier.h"

class EarthSoldierList {
    private:
    LinkedQueue<EarthSoldier*> queue;
    // Node<T>* backPtr;
    // Node<T>* frontPtr;
    // int count;

    public:
    bool add(EarthSoldier* unit);
    bool remove(EarthSoldier*& unit);
    void print();
    bool isEmpty();
    int getCount();
    bool peek(EarthSoldier* unit);
};
