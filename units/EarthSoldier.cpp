#include "EarthSoldier.h"

EarthSoldier::EarthSoldier(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, E_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void EarthSoldier::attack(int timeStep) {}