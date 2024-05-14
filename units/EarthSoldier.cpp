#include "../units/EarthSoldier.h"
#include "../game.h"
// #include "AlienArmy.h"
EarthSoldier::EarthSoldier(int ID, int timeStep, int health, int power,
                            int attackCapacity, const Game* game)
    : Unit(ID, E_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void EarthSoldier::attack(){
    AlienSoldierList* alienSoldierList = game->getAlienArmy()->getASList();
    LinkedQueue<AlienSoldier*>* tempList;
    AlienSoldier *alienSoldier;   
    for (int i = 0; i < attackCapacity;i++){
        alienSoldierList->remove(alienSoldier);
        tempList->enqueue(alienSoldier);
    }
    int tempListSoldiernum = tempList->getCount();
    for (int i = 0; i < tempListSoldiernum; i++){
        tempList->dequeue(alienSoldier);
        int damage = this->getPower() * (this->getHealth() / 100) / sqrt(alienSoldier->getHealth());
        alienSoldier->setHealth(getHealth() - damage);
        if(alienSoldier->getHealth() <= 0){
            game->getKilled()->add(alienSoldier);
        }else {
            game->getAlienArmy()->addUnit(alienSoldier);
        }
    }
}