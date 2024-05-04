#include "EarthTank.h"
#include "game.h"
#include "AlienArmy.h"
EarthTank::EarthTank(int ID, int timeStep, int health, int power,
                     int attackCapacity, const Game* game)
    : Unit(ID, E_TANK, timeStep, health, power, attackCapacity, game) {}

void EarthTank::attack() {
}
