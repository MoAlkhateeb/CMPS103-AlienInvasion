#include "AlienDrone.h"
#include "../game.h"

AlienDrone::AlienDrone(int ID, int timeStep, int health, int power,
                       int attackCapacity, const Game* game)
    : Unit(ID, A_DRONE, timeStep, health, power, attackCapacity, game) {}

void AlienDrone::attack(int timeStep, Mode operation) {

    Game* game = getGame(); 

    int capacity = getAttackCapacity();

    EarthTankList* tanks = game->getEarthArmy()->getETList();
    EarthGunneryList* gunneries = game->getEarthArmy()->getEGList();

    LinkedQueue<Unit*> tempList;

    EarthTank* tank;
    EarthGunnery* gunnery;

    bool noTanks = false;
    bool noGunnery = false;

    while (capacity > 0) {
        if (tanks->remove(tank)) {
            tempList.enqueue(tank);
            setFirstAttackTime(timeStep);
            tank->setHealth(tank->getHealth() - getDamage(tank));
            capacity--;
        }
        else {
            noTanks = true;
        }

        if (gunneries->remove(gunnery)) {
            tempList.enqueue(gunnery);
            setFirstAttackTime(timeStep);
            gunnery->setHealth(gunnery->getHealth() - getDamage(gunnery));
            capacity--;
        }
        else {
            noGunnery = true;
        }

        if (noTanks && noGunnery) break;
    }

    if (operation == INTERACTIVE && tempList.getCount() > 0) {
        cout << "AD " << getID() << " ";
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