#include "EarthSoldier.h"
#include "game.h"
// #include "AlienArmy.h"
EarthSoldier::EarthSoldier(int ID, int timeStep, int health, int power,
                            int attackCapacity, const Game* game)
    : Unit(ID, E_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void EarthSoldier::attack(){
    AlienSoldierList* alienSoldierList = game->getAlienArmy()->getASList();
    LinkedQueue<AlienSoldier*>* tempSoldierList;
    AlienSoldier *alienSoldier;
    for (int i = 0; i < attackCapacity;i++){
        alienSoldierList->remove(alienSoldier);
        tempSoldierList->enqueue(alienSoldier);
    }
    int tempSoldiernum = tempSoldierList->getCount();
    for (int i = 0; i < tempSoldiernum; i++)
    {
        int damage = this->getPower() * (this->getHealth() / 100) / sqrt(tempSoldierList->getItem()->getHealth());
        tempSoldierList->getItem()->setHealth(getHealth() - damage);
        tempSoldierList->dequeue(alienSoldier);
        if(alienSoldier->getHealth() <= 0){
            game->getKilled()->add(alienSoldier);
        }else {
            game->getAlienArmy()->addUnit(alienSoldier);
        }
    }
}