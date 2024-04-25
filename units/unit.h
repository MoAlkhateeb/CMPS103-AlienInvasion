#pragma once

#include <fstream>
#include <iostream>


using namespace std;

class Game;

enum UnitType { E_SOLDIER, E_TANK, E_GUNNERY, A_SOLDIER, A_MONSTER, A_DRONE };

class Unit {
   protected:
    const int ID;
    const UnitType type;
    int health;
    const int power;
    const int attackCapacity;

    const int timeStep;    // Tj
    int destructionTime;   // Td
    int firstAttackTime;   // Ta
    int destructionDelay;  // Dd
    int firstAttackDelay;  // Df
    int battleTime;        // Db

    const Game* game;

   public:
    Unit(int ID, UnitType type, int timeStep, int health, int power,
         int attackCapacity, const Game* game);

    int getID() const;
    UnitType getType() const;

    int getHealth() const;
    int getPower() const;
    int getAttackCapacity() const;

    int getTimeStep() const;
    int getDestructionTime() const;
    int getFirstAttackDelay()const;
    int getFirstAttackTime()const;
    int getBattleTime()const;

    void setHealth(int h);

    bool setDestructionTime(int time);
    bool setFirstAttackTime(int time);

    virtual void attack() = 0;
};

ostream& operator<<(ostream& os, const Unit& obj);
ofstream& operator<<(ofstream& fs, const Unit& obj);