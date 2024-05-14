#pragma once

#include "Unit.h"

class AlienDrone : public Unit {
   public:
    AlienDrone(int ID, int timeStep, int health, int power, int attackCapacity,
               const Game* game);

    void attack(int timeStep, Mode operation) override;
};