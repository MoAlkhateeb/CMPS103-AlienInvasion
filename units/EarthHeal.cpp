#include "../game.h"
#include "EarthHeal.h"
#include "../lists/EarthSoldierMaintainList.h"

EarthHeal::EarthHeal(int ID, int timeStep, int health, int power,
    int attackCapacity, const Game* game)
    : Unit(ID, E_HEAL, timeStep, health, power, attackCapacity, game) {}

void EarthHeal::attack(int timeStep) {
    EarthSoldierMaintainList* soldiers = getGame()->getEarthSoldierMaintainList();
    TankMaintainList* tanks = getGame()->getTankMaintainList();
    HealList* healUnits = getGame()->getHealList();

    // TODO



}