#pragma once

#include "Unit.h"

class AlienMonster : public Unit {
   public:
    AlienMonster(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game);

    void attack(int timeStep) override;
};