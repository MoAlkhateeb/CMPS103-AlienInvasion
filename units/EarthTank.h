#pragma once

#include "Unit.h"

class EarthTank : public Unit {
   public:
    EarthTank(int ID, int timeStep, int health, int power, int attackCapacity,
              const Game* game);

    void attack(int timeStep) override;
};