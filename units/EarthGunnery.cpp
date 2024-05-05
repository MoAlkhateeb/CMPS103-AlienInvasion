#include "EarthGunnery.h"
#include "game.h"
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

    for (int i = 0; i < egList->getCount();i++){
        EarthGunnery *eg = nullptr;
        egList->remove(eg);
        if(eg){
            int currentPriority = eg->getPriority();
            if(currentPriority > highestPriority){
                highestPriority = currentPriority;
                highestPriGunnery = eg;
            }
            egList->add(eg);
        }
    }
    if(!highestPriGunnery){
        cout << "No Earth Gunnery available";
        return;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> monsterDist(0, monsterList->getCount() - 1);
    int monsterIndex = monsterDist(gen);
    AlienMonster *targetMonster = nullptr;
    int monsterIndex = monsterDist(gen); // Pick random monster
    
    AlienMonster *targetMonster = nullptr;
    if(monsterList->remove(targetMonster)){
        cout << "EarthGunnery" << highestPriGunnery->getID() << "attacks monster" << targetMonster->getID() << endl;
    }else {
        cout << "No monsters to attack!" << endl;
    }

    // Attack drones in pairs if available, otherwise attack a single drone
    AlienDrone *firstDrone = nullptr;
    AlienDrone *secondDrone = nullptr;
    if(droneList->remove(firstDrone,secondDrone)){
        cout << "EarthGunnery" << highestPriGunnery->getID() << "attacks drones" << firstDrone->getID() << "and" <<secondDrone->getID() << endl;
    } else if(firstDrone ){
        cout << "EarthGunnery" << highestPriGunnery->getID() << "attacks drone" << firstDrone->getID() << endl;
    } else {
        cout << "No drones available to attack" << endl;
    }
}
