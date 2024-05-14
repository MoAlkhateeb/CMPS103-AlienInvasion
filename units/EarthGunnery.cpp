#include "EarthGunnery.h"
#include "../game.h"

EarthGunnery::EarthGunnery(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, E_GUNNERY, timeStep, health, power, attackCapacity, game) {}

int EarthGunnery::getPriority() const {
    // prioritize health over power
    return getHealth() + 0.7 * getPower();
}

void EarthGunnery::attack(int timeStep, Mode operation) {

    Game* game = getGame();
    AlienMonsterList* monsters = game->getAlienArmy()->getAMList();
    AlienDroneList* drones = game->getAlienArmy()->getADList();

    int capacity = getAttackCapacity();

    AlienMonster* monster;
    AlienDrone* AD1, * AD2;

    LinkedQueue<Unit*> tempList;
    bool noMonster = false;
    bool noDrones = false;

    while (capacity > 0) {
        if (monsters->remove(monster)) {
            tempList.enqueue(monster);
            monster->setHealth(monster->getHealth() - getDamage(monster));
            setFirstAttackTime(timeStep);
            capacity--;
        }
        else {
            noMonster = true;
        }

        if (drones->remove(AD1, AD2)) {
            tempList.enqueue(AD1);
            AD1->setHealth(AD1->getHealth() - getDamage(AD1));
            capacity--;
            setFirstAttackTime(timeStep);

            if (AD2) {
                tempList.enqueue(AD2);
                AD2->setHealth(AD2->getHealth() - getDamage(AD2));
                capacity--;
            }
        }
        else {
            noDrones = true;
        }

        if (noDrones && noMonster) break;
    }

    if (tempList.getCount() == 0) return;

    if (operation == INTERACTIVE) {
        cout << "EG " << getID() << " ";
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
            game->getAlienArmy()->addUnit(current);
        }
    }
    
}
