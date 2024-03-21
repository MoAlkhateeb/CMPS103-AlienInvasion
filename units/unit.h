#include "../game.h"

enum UnitType { E_SOLDIER, E_TANK, E_GUNNERY, A_SOLDIER, A_MONSTER, A_DRONE };

class Unit {
    const int ID;
    const UnitType type;
    const int timeStep;
    const int health;
    const int power;
    const int attackCapacity;

    const Game* game;

    Unit();
    virtual void attack() = 0;
};