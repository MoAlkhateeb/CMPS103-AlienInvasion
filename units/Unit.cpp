#include "Unit.h"

Unit::Unit(int ID, UnitType type, int timeStep, int health, int power,
        int attackCapacity, const Game* game)
    : ID(ID),
    type(type),
    timeStep(timeStep),
    health(health),
    initialHealth(health),
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
Game* Unit::getGame() const { return (Game*) game;  }
int Unit::getInitialHealth() const { return initialHealth; }
int Unit::getHealth() const { return health; }
int Unit::getPower() const { return power; }
int Unit::getAttackCapacity() const { return attackCapacity; }
int Unit::getDestructionTime() const { return destructionTime; }
int Unit::getTimeStep() const { return timeStep; }
int Unit::getFirstAttackDelay() const{ return firstAttackDelay; }
int Unit::getFirstAttackTime() const { return firstAttackTime; }

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

int Unit::getDamage(Unit* other) const {
    int damage = ((power * health) / 100.0) / sqrt(other->getHealth());

    if (type == E_HEAL) {
        damage = damage * -1;
    }

    return damage;
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
    fs << obj.getFirstAttackDelay() << " " << obj.getFirstAttackTime() << " ";
    fs << obj.getBattleTime();
    return fs;
}