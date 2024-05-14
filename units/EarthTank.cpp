#include "EarthTank.h"

EarthTank::EarthTank(int ID, int timeStep, int health, int power,
                     int attackCapacity, const Game* game)
    : Unit(ID, E_TANK, timeStep, health, power, attackCapacity, game) {}

void EarthTank::attack(int timeStep) {}
