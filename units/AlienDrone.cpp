#include "AlienDrone.h"

AlienDrone::AlienDrone(int ID, int timeStep, int health, int power,
                       int attackCapacity, const Game* game)
    : Unit(ID, A_DRONE, timeStep, health, power, attackCapacity, game) {}

void AlienDrone::attack(int timeStep, Mode operation) {}