#include "../game.h"
#include "AlienSoldier.h"
#include "../structures/LinkedQueue.h"
#include "../units/EarthSoldier.h"
#include "../lists/EarthSoldierMaintainList.h"

AlienSoldier::AlienSoldier(int ID, int timeStep, int health, int power,
                           int attackCapacity, const Game* game)
    : Unit(ID, A_SOLDIER, timeStep, health, power, attackCapacity, game) {}

void AlienSoldier::attack(int timeStep, Mode operation) {

    Game* game = getGame();
    
    int AttackCapacity = getAttackCapacity();
    EarthSoldierMaintainList* maintain = game->getEarthSoldierMaintainList();

    LinkedQueue<EarthSoldier*> temp;

    if (operation == INTERACTIVE && game->getEarthArmy()->getESList()->getCount())
        cout << "AS " << getID() << " shots [ ";

    for (int i = AttackCapacity; i > 0; i--)
    {
        EarthSoldier* enemy;
        bool isEnemy = game->getEarthArmy()->getESList()->remove(enemy);
        int initialHealth;

        if (isEnemy) {
            initialHealth = enemy->getHealth();
            enemy->setHealth(initialHealth - getDamage(enemy));
            setFirstAttackTime(timeStep);
            if (operation == INTERACTIVE)
                cout << enemy->getID() << " ";
        }


        if (isEnemy && enemy->getHealth() <= 0) {
            game->getKilled()->add(enemy);
            enemy->setDestructionTime(timeStep);
        }
        else if (isEnemy && enemy->getHealth() < 20 / 100 * initialHealth) {
            maintain->add(enemy);
        }
        else {
            temp.enqueue(enemy);
        }
    }

    if (operation == INTERACTIVE && game->getEarthArmy()->getESList()->getCount())
        cout << "]" << endl;

    while (!temp.isEmpty())
    {
        EarthSoldier* tempsoldier;
        temp.dequeue(tempsoldier);
        game->getEarthArmy()->getESList()->add(tempsoldier);
    }

}