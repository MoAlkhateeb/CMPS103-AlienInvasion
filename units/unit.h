#pragma once

#include <fstream>
#include <iostream>


using namespace std;

class Game;

enum UnitType { E_SOLDIER, E_TANK, E_GUNNERY, E_HEAL, A_SOLDIER, A_MONSTER, A_DRONE };

class Unit {
   private:
    const int ID;
    const UnitType type;
    int health;
    const int initialHealth;
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

    Game* getGame() const;

    int getID() const;
    UnitType getType() const;

    int getHealth() const;
    int getPower() const;
    int getDamage(Unit* other) const;
    int getInitialHealth() const;
    int getAttackCapacity() const;

    int getTimeStep() const;
    int getDestructionTime() const;
    int getFirstAttackDelay()const;
    int getFirstAttackTime()const;
    int getBattleTime()const;

    void setHealth(int h);

    bool setDestructionTime(int time);
    bool setFirstAttackTime(int time);

    virtual void attack(int timeStep) = 0;
};

ostream& operator<<(ostream& os, const Unit& obj);
ofstream& operator<<(ofstream& fs, const Unit& obj);