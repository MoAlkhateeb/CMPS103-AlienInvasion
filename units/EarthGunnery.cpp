#include "../units/EarthGunnery.h"
#include "../game.h"
EarthGunnery::EarthGunnery(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, E_GUNNERY, timeStep, health, power, attackCapacity, game) {}

int EarthGunnery::getPriority() const {
    // prioritize health over power
    return getHealth() + 0.7 * getPower();
}

void EarthGunnery::attack() {
    AlienArmy *alienArmy = game->getAlienArmy();
    if(!alienArmy){
        cout << "Alien Army not available! ";
        return;
    }

    AlienDroneList *droneList = alienArmy->getADList();
    if(!droneList){
        cout << "Drone List is not available";
        return;
    }

    AlienMonsterList *monsterList = alienArmy->getAMList();
    if(!monsterList){
        cout << "Monster List is not available";
        return;
    }

    int priority = getPriority();

    EarthGunneryList *egList = game->getEarthArmy()->getEGList();
    if(!egList){
        cout << "Earth GunneryList is not available";
        return;
    }

    EarthGunnery *highestPriGunnery = nullptr;
    int highestPriority = -1;

    egList->remove(highestPriGunnery);
    if(!highestPriGunnery){
        cout << "No Earth Gunnery available";
        return;
    }

    AlienMonster *targetMonster = nullptr;
    if(monsterList->remove(targetMonster)){
        cout << "EarthGunnery" << highestPriGunnery->getID() << "attacks monster" << targetMonster->getID() << endl;
        int damage = highestPriGunnery->getPower();
        int currentHealth = targetMonster->getHealth();
        targetMonster->setHealth(currentHealth - damage);
        if(currentHealth <=0){
            game->getKilled()->add(targetMonster);
        }
        else
        {
            game->getAlienArmy()->getAMList()->add(targetMonster);
        }
    }
    else
    {
        cout << "No monsters to attack!" << endl;
    }

    // Attack drones in pairs if available, otherwise attack a single drone
    AlienDrone *firstDrone = nullptr;
    AlienDrone *secondDrone = nullptr;
    if(droneList->remove(firstDrone,secondDrone)){
        // cout << "EarthGunnery" << highestPriGunnery->getID() << "attacks drones" << firstDrone->getID() << "and" <<secondDrone->getID() << endl;
        int damage = highestPriGunnery->getPower();
        int currentHealth1 = firstDrone->getHealth();
        int currentHealth2;
        if(secondDrone)
            currentHealth2 = secondDrone->getHealth();
        firstDrone->setHealth(currentHealth1 - damage);
        if (firstDrone->getHealth() <= 0)
        {
            game->getKilled()->add(firstDrone);
        }
        else {
            game->getAlienArmy()->getADList()->add(firstDrone);
        }
        secondDrone->setHealth(currentHealth2 - damage);
        if(secondDrone && secondDrone->getHealth() <= 0){
            game->getKilled()->add(secondDrone);
        }
        else
        {
            game->getAlienArmy()->getADList()->add(secondDrone);
        }
    }
    else
    {
        cout << "No drones available to attack" << endl;
    }
}
