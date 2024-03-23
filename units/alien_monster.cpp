#include "unit.h"

class AlienMonster : public Unit {
   public:
    AlienMonster(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game)
        : Unit(ID, A_MONSTER, timeStep, health, power, attackCapacity, game) {}

    void attack() override {}
};