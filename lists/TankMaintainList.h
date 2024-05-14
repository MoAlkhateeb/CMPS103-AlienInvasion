#pragma once

#include "../structures/LinkedQueue.h"
#include "../units/EarthTank.h"

class TankMaintainList {
private:
    LinkedQueue<EarthTank*> queue;

public:
    bool add(EarthTank* unit);
    bool remove(EarthTank*& unit);
    void print();

    int getCount() const;
};