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
    for (int i = 0; i < tempSoldierList->getCount();i++){
        tempSoldierList->getItem()[i].setHealth(getHealth() - power);
        tempSoldierList[i].dequeue(alienSoldier);
        if(alienSoldier->getHealth() <= 0){
            game->getKilled()->add(alienSoldier);
        }else {
            game->getAlienArmy()->addUnit(alienSoldier);
        }
    }
}