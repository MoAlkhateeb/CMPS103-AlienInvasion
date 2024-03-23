#include "unit.h"

class EarthTank : public Unit {
   public:
    EarthTank(int ID, int timeStep, int health, int power, int attackCapacity,
              const Game* game)
        : Unit(ID, E_TANK, timeStep, health, power, attackCapacity, game) {}

    void attack() override {}
};