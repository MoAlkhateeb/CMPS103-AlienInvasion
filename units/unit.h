#pragma once

#include <iostream>
#include <fstream>

#include "../game.h"

using namespace std;

enum UnitType { E_SOLDIER, E_TANK, E_GUNNERY, A_SOLDIER, A_MONSTER, A_DRONE };

class Unit {
   private:
    const int ID;
    const UnitType type;
    const int health;
    const int power;
    const int attackCapacity;

    const int timeStep;   // Tj
    int destructionTime;  // Td
    int firstAttackTime;  // Ta
    int destructionDelay; // Dd
    int firstAttackDelay; // Df
    int battleTime;       // Db

    const Game* game;

   public:
    Unit(int ID, UnitType type, int timeStep, int health, int power,
         int attackCapacity, const Game* game);

    int getID() const;
    UnitType getType() const;
    int getHealth() const;
    int getPower() const;
    int getAttackCapacity() const;

    bool setDestructionTime(int time);
    bool setFirstAttackTime(int time);

    virtual void attack() = 0;

    friend ostream& operator<<(ostream& os, const Unit& obj);
    friend ofstream& operator<<(ofstream& os, const Unit& obj);
};