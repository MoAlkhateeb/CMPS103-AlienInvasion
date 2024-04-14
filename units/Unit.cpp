#include "Unit.h"

Unit::Unit(int ID, UnitType type, int timeStep, int health, int power,
        int attackCapacity, const Game* game)
    : ID(ID),
    type(type),
    timeStep(timeStep),
    health(health),
    power(power),
    attackCapacity(attackCapacity),
    game(game) {
    destructionTime = -1;
    firstAttackTime = -1;
    destructionDelay = -1;
    firstAttackDelay = -1;
    battleTime = -1;
}

int Unit::getID() const { return ID; }

UnitType Unit::getType() const { return type; }

int Unit::getHealth() const { return health; }
int Unit::getPower() const { return power; }
int Unit::getAttackCapacity() const { return attackCapacity; }
int Unit::getDestructionTime() const { return destructionTime; }
int Unit::getTimeStep() const { return timeStep; }
int Unit::getfirstAttackDelay() const{ return firstAttackDelay; }
int Unit::getfirstAttackTime() const{ return firstAttackTime; }
int Unit::getBattleTime() const{ return battleTime; }
bool Unit::setDestructionTime(int time) {
    if (time < timeStep || time < 0) return false;
    destructionTime = time;
    destructionDelay = destructionTime - firstAttackTime;
    battleTime = destructionTime - timeStep;
    return true;
}

bool Unit::setFirstAttackTime(int time) {
    if (time < timeStep || time < 0) return false;
    firstAttackTime = time;
    firstAttackDelay = firstAttackTime - timeStep;
    return true;
}

void Unit::setHealth(int h) {
    health = h;
}

ostream& operator<<(ostream& os, const Unit& obj) {
    os << obj.getID();
    return os;
}

ofstream& operator<<(ofstream& fs, const Unit& obj) {
    fs << obj.getDestructionTime() << " " << obj.getID() << " " << obj.getTimeStep() << " ";
    fs << obj.getfirstAttackDelay() << " " << obj.getfirstAttackTime() << " ";
    fs << obj.getBattleTime();
    return fs;
}