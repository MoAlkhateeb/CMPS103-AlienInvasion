#include "EarthSoldier.h"
#include "../game.h"

EarthSoldier::EarthSoldier(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, E_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void EarthSoldier::attack(int timeStep, Mode operation) {
    Game* game = getGame();

    AlienSoldierList* alienSoldierList = game->getAlienArmy()->getASList();
    LinkedQueue<AlienSoldier*> tempList;
    AlienSoldier* alienSoldier;

    int initialCapacity = getAttackCapacity();
    for (int i = 0; i < initialCapacity; i++)
    {
        if (alienSoldierList->remove(alienSoldier))
            tempList.enqueue(alienSoldier);
        else
            break;
    }


    int tempListSoldierNum = tempList.getCount();

    if (!tempListSoldierNum) return;

    if (operation == INTERACTIVE)
        cout << "ES " << getID() << " shots [ ";

    for (int i = 0; i < tempListSoldierNum; i++) {
        tempList.dequeue(alienSoldier);
        int damage = getDamage(alienSoldier);
        setFirstAttackTime(timeStep);

        if (operation == INTERACTIVE)
            cout << alienSoldier->getID() << " ";

        alienSoldier->setHealth(alienSoldier->getHealth() - damage);
        if (alienSoldier->getHealth() <= 0) {
            game->getKilled()->add(alienSoldier);
            alienSoldier->setDestructionTime(timeStep);
        }
        else {
            game->getAlienArmy()->addUnit(alienSoldier);
        }
    }

    if (operation == INTERACTIVE)
        cout << "]" << endl;
}