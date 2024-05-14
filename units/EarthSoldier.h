#pragma once

#include "Unit.h"

class EarthSoldier : public Unit {
   public:
    EarthSoldier(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game);

    void attack() override;
};