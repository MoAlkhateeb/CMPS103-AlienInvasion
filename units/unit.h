#pragma once

#include <iostream>
#include "../game.h"

using namespace std;

enum UnitType { E_SOLDIER, E_TANK, E_GUNNERY, A_SOLDIER, A_MONSTER, A_DRONE };

class Unit {
   private:
    const int ID;
    const UnitType type;
    const int timeStep;
    const int health;
    const int power;
    const int attackCapacity;

    const Game* game;

   public:
    Unit(int ID, UnitType type, int timeStep, int health, int power,
         int attackCapacity, const Game* game)
        : ID(ID),
          type(type),
          timeStep(timeStep),
          health(health),
          power(power),
          attackCapacity(attackCapacity),
          game(game) {}

    int getID() const { return ID; }
    UnitType getType() const { return type; }
    int getTimeStep() const { return timeStep; }
    int getHealth() const { return health; }
    int getPower() const { return power; }
    int getAttackCapacity() const { return attackCapacity; }
    
    virtual void attack() = 0;

    friend ostream& operator<<(ostream& os, const Unit& obj) {
        os << obj.ID;
        return os;
    }
};