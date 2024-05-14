#include "EarthHeal.h"

EarthHeal::EarthHeal(int ID, int timeStep, int health, int power,
    int attackCapacity, const Game* game)
    : Unit(ID, E_HEAL, timeStep, health, power, attackCapacity, game) {}

void EarthHeal::attack() {}