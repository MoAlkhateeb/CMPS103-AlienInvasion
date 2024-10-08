#include "EarthGunnery.h"
#include "game.h"
EarthGunnery::EarthGunnery(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, E_GUNNERY, timeStep, health, power, attackCapacity, game) {}

int EarthGunnery::getPriority() const {
    // prioritize health over power
    return getHealth() + 0.7 * getPower();
}

void EarthGunnery::attack() {}
