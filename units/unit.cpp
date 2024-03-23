#include "unit.h"

#include "../game.h"

Unit::Unit(int ID, UnitType type, int timeStep, int health, int power,
           int attackCapacity, const Game* game)
    : ID(ID),
      type(type),
      timeStep(timeStep),
      health(health),
      power(power),
      attackCapacity(attackCapacity),
      game(game) {}