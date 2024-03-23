#include "unit.h"

class EarthSoldier : public Unit {
   public:
    EarthSoldier(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game)
        : Unit(ID, E_SOLDIER, timeStep, health, power, attackCapacity, game) {}

    void attack() override {}
};