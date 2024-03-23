#include "unit.h"

class AlienDrone : public Unit {
   public:
    AlienDrone(int ID, int timeStep, int health, int power, int attackCapacity,
               const Game* game)
        : Unit(ID, A_DRONE, timeStep, health, power, attackCapacity, game) {}

    void attack() override {}
};