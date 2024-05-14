#include "../game.h"
#include "EarthHeal.h"
#include "../lists/EarthSoldierMaintainList.h"

EarthHeal::EarthHeal(int ID, int timeStep, int health, int power,
    int attackCapacity, const Game* game)
    : Unit(ID, E_HEAL, timeStep, health, power, attackCapacity, game) {}

void EarthHeal::attack(int timeStep, Mode operation) {
    EarthSoldierMaintainList* soldiers = getGame()->getEarthSoldierMaintainList();
    TankMaintainList* tanks = getGame()->getTankMaintainList();
    
    int initialCapacity = getAttackCapacity();

    EarthSoldier* currentSoldier;
    EarthTank* currentTank;
    while (initialCapacity > 0) {
        if (soldiers->remove(currentSoldier)) {
            currentSoldier->setHealth(currentSoldier->getHealth() + getDamage(currentSoldier));
            initialCapacity--;
        }
        else {
            break;
        }
    }

    while (initialCapacity > 0) {
        if (tanks->remove(currentTank)) {
            currentTank->setHealth(currentTank->getHealth() + getDamage(currentTank));
            initialCapacity--;
        }
        else {
            break;
        }
    }


}