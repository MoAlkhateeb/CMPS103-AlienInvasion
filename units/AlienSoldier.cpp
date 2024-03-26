#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, A_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void AlienSoldier::attack() {}