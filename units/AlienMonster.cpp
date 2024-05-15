#include "AlienMonster.h"
#include "../game.h"

AlienMonster::AlienMonster(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, A_MONSTER, timeStep, health, power, attackCapacity, game) {}

void AlienMonster::attack(int timeStep, Mode operation) {
    Game* game = getGame();
    EarthTankList* tanks = game->getEarthArmy()->getETList();
    EarthSoldierList* soldiers = game->getEarthArmy()->getESList();

    int capacity = getAttackCapacity();

    EarthTank* tank;
    EarthSoldier* soldier;

    LinkedQueue<Unit*> tempList;
    bool notank = false;
    bool nosoldier = false;

    while (capacity > 0) {
        if (tanks->remove(tank)) {
            tank->setHealth(tank->getHealth() - getDamage(tank));
            tempList.enqueue(tank);
            setFirstAttackTime(timeStep);
            capacity--;
        }
        else {
            notank = true;
        }


        if (capacity > 0 && soldiers->getCount() > 0 && soldiers->remove(soldier)) {
            soldier->setHealth(soldier->getHealth() - getDamage(soldier));
            tempList.enqueue(soldier);
            capacity--;
            setFirstAttackTime(timeStep);
        
        }
        else {
            nosoldier = true;
        }

        if (notank && nosoldier) break;
    }

    if (tempList.getCount() == 0) return;

    if (operation == INTERACTIVE) {
        cout << "AM " << getID() << " ";
        tempList.print();
    }

    Unit* current;
    for (int i = 0; i < tempList.getCount(); i++) {
        tempList.dequeue(current);
        if (current->getHealth() <= 0) {
            game->getKilled()->add(current);
            current->setDestructionTime(timeStep);
        }
        else {
            game->getEarthArmy()->addUnit(current);
        }
    }
}