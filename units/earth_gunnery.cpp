#include "unit.h"

class EarthGunnery : public Unit {
   public:
    EarthGunnery(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game)
        : Unit(ID, E_GUNNERY, timeStep, health, power, attackCapacity, game) {}

    void attack() override {}
};