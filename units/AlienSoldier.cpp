#include "AlienSoldier.h"
#include "game.h"
AlienSoldier::AlienSoldier(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, A_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void AlienSoldier::attack() {
    EarthSoldierList* earthSoldierList = game->getEarthArmy()->getESList();
    LinkedQueue<EarthSoldier*>* tempSoldierList;
    EarthSoldier *earthsoldier;
    for (int i = 0; i < attackCapacity;i++){
        earthSoldierList->remove(earthsoldier);
        tempSoldierList->enqueue(earthsoldier);
    }
    int tempSoldiernum = tempSoldierList->getCount();
    for (int i = 0; i < tempSoldiernum; i++)
    {
        int damage = this->getPower() * (this->getHealth() / 100) / sqrt(tempSoldierList->getItem()->getHealth());
        tempSoldierList->getItem()->setHealth(getHealth() - damage);
        tempSoldierList->dequeue(earthsoldier);
        if(earthsoldier->getHealth() <= 0){
            game->getKilled()->add(earthsoldier);
        }else {
            game->getEarthArmy()->addUnit(earthsoldier);
        }
    }
}