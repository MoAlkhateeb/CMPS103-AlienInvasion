#include "../units/AlienSoldier.h"
#include "../game.h"
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
        tempSoldierList->dequeue(earthsoldier);
        int damage = this->getPower() * (this->getHealth() / 100) / sqrt(earthsoldier->getHealth());
        earthsoldier->setHealth(getHealth() - damage);
        if(earthsoldier->getHealth() <= 0){
            game->getKilled()->add(earthsoldier);
        }else {
            game->getEarthArmy()->addUnit(earthsoldier);
        }
    }
}