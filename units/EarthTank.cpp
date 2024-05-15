#include "EarthTank.h"
#include "../game.h"

EarthTank::EarthTank(int ID, int timeStep, int health, int power,
                     int attackCapacity, const Game* game)
    : Unit(ID, E_TANK, timeStep, health, power, attackCapacity, game) {}

void EarthTank::attack(int timeStep, Mode operation) {
    Game* game = getGame();

    AlienMonsterList* monsters = game->getAlienArmy()->getAMList();
    AlienSoldierList* soldiers = game->getAlienArmy()->getASList();
    
    int EarthSoldierCount = game->getEarthArmy()->getESList()->getCount();
    int AlienSoldierCount = soldiers->getCount();
    bool shouldAttackSoldiers = EarthSoldierCount < 0.3 * AlienSoldierCount;
    int capacity = getAttackCapacity();

    AlienMonster* monster;
    AlienSoldier* soldier;

    LinkedQueue<Unit*> tempList;
    bool noMonster = false;
    bool noSoldiers = true;

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

        while (capacity  > 0 && shouldAttackSoldiers) {
            if (soldiers->remove(soldier)) {
                tempList.enqueue(soldier);
                soldier->setHealth(soldier->getHealth() - getDamage(soldier));
                setFirstAttackTime(timeStep);
                capacity--;
            }
            else {
                noSoldiers = true;
                break;
            }
        }

        if (noSoldiers && noMonster) break;
    }

    if (tempList.getCount() == 0) return;

    if (operation == INTERACTIVE) {
        cout << "ET " << getID() << " ";
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
