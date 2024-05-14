#pragma once

#include "Unit.h"

class AlienSoldier : public Unit {
   public:
    AlienSoldier(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game);

    void attack() override;
};