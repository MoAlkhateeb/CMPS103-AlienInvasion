#include "AlienMonster.h"

AlienMonster::AlienMonster(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, A_MONSTER, timeStep, health, power, attackCapacity, game) {}

void AlienMonster::attack(int timeStep, Mode operation) {}