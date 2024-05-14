#pragma once

#include "Unit.h"

class EarthHeal : public Unit {
public:
    EarthHeal(int ID, int timeStep, int health, int power,
        int attackCapacity, const Game* game);

    void attack(int timeStep, Mode operation) override;
};