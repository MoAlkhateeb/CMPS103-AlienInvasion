#include "AlienSoldier.h"
#include "game.h"
AlienSoldier::AlienSoldier(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, A_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void AlienSoldier::attack() {
    EarthSoldierList *earthSoldierList = game->getEarthArmy()->getESList();
    LinkedQueue<EarthSoldier *> tempSoldierList;
    for (int i = 0; i < attackCapacity; i++){
        EarthSoldier *earthSoldier;
        if(earthSoldierList->remove(earthSoldier)){
            tempSoldierList.enqueue(earthSoldier);
        }
    }
    while (!tempSoldierList.isEmpty())
    {
        EarthSoldier *earthSoldier;
        tempSoldierList.dequeue(earthSoldier);
        earthSoldier->setHealth(earthSoldier->getHealth() - power);
        if(earthSoldier->getHealth() <= 0){
            game->getKilled()->add(earthSoldier);
        }else {
            game->getEarthArmy()->addUnit(earthSoldier);
        }
    }
}