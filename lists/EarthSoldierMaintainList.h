#pragma once

#include "../structures/PriQueue.h"
#include "../units/EarthSoldier.h"

class EarthSoldierMaintainList {
private:
    PriQueue<EarthSoldier*> priQueue;

public:
    bool add(EarthSoldier* unit);
    bool remove(EarthSoldier*& unit);
    void print();

    int getCount() const;
};