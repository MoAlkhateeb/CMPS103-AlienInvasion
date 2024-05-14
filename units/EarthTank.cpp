#include "EarthTank.h"
#include "../game.h"
#include "../armies/AlienArmy.h"
#include "../structures/ArrayStack.h"
using namespace std;
EarthTank::EarthTank(int ID, int timeStep, int health, int power,
                     int attackCapacity, const Game *game)
    : Unit(ID, E_TANK, timeStep, health, power, attackCapacity, game) {}

void EarthTank::attack() {
    int i = 0;
    while (i < attackCapacity){
        if (game->getEarthArmy()->getESList()->getCount() < 0.3 * game->getAlienArmy()->getASList()->getCount())
        {
            while (game->getEarthArmy()->getESList()->getCount() < 0.8 * game->getAlienArmy()->getASList()->getCount())
            {
                int numAliensSoldiers = game->getAlienArmy()->getASList()->getCount();
                int numSoldiersToAttack = std::min(attackCapacity, numAliensSoldiers);
                for (int i = 0; i < numSoldiersToAttack; ++i)
                {
                    int randomAlienIndex = rand() % numAliensSoldiers;
                    game->getAlienArmy()->attack();
                }
            }
        }
        else
        {
            int numMonsters = game->getAlienArmy()->getAMList()->getCount();
            int numMonstersToAttack = std::min(attackCapacity, numMonsters);
            for (int i = 0; i < numMonstersToAttack; ++i)
            {
                int randomMonsterIndex = rand() % numMonsters;
                game->getAlienArmy()->attack();
            }
        }
    }
}
