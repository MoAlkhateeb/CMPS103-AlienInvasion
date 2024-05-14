#include "randomGen.h"

#include <random>

#include "../game.h"
#include "../units/EarthHeal.h"

RandGen::RandGen(Game* game)
    : game(game), gen(rd()), Prob(1, 100) {}



void RandGen::createUnits(int timeStep) {

    int A = getRandomNumber();

    if (A < generateProb) {
        EarthArmy* earthArmy = game->getEarthArmy();

        for (int i = 0; i < N; i++) {
            Unit* generatedUnit = generateRandomEarthUnit(timeStep);
            if (generatedUnit->getType() == E_HEAL) {
                game->getHealList()->add(generatedUnit);
            }
            else {
                earthArmy->addUnit(generatedUnit);
            }
        }
    }

    A = getRandomNumber();

    if (A < generateProb) {
        AlienArmy* alienArmy = game->getAlienArmy();
        for (int i = 0; i < N; i++) {
            Unit* generatedUnit = generateRandomAlienUnit(timeStep);
            alienArmy->addUnit(generatedUnit);
        }
    }
}

Unit* RandGen::generateUnit(int ID, int timeStep, int power, int health,
                            int capacity, UnitType type) const {
    switch (type) {
        case E_SOLDIER:
            return new EarthSoldier(ID, timeStep, health, power, capacity, game);

        case E_TANK:
            return new EarthTank(ID, timeStep, health, power, capacity, game);

        case E_GUNNERY:
            return new EarthGunnery(ID, timeStep, health, power, capacity, game);
        
        case E_HEAL:
            return new EarthHeal(ID, timeStep, health, power, capacity, game);

        case A_SOLDIER:
            return new AlienSoldier(ID, timeStep, health, power, capacity, game);

        case A_MONSTER:
            return new AlienMonster(ID, timeStep, health, power, capacity, game);

        case A_DRONE:
            return new AlienDrone(ID, timeStep, health, power, capacity, game);

        default: return nullptr;
    }
}

Unit* RandGen::generateRandomAlienUnit(int timeStep) {
    uniform_int_distribution<> A_Power(APower.start, APower.end);
    uniform_int_distribution<> A_Health(AHealth.start, AHealth.end);
    uniform_int_distribution<> A_Capacity(AAttack.start, AAttack.end);

    int power = A_Power(gen);
    int health = A_Health(gen);
    int capacity = A_Capacity(gen);

    int B = getRandomNumber();

    if (B < ASPercent) {
        return generateUnit(alienID++, timeStep, power, health, capacity, A_SOLDIER);
    } else if (B < ASPercent + AMPercent) {
        return generateUnit(alienID++, timeStep, power, health, capacity, A_MONSTER);
    } else if(B < ASPercent + AMPercent+ ADPercent) {
        return generateUnit(alienID++, timeStep, power, health, capacity, A_DRONE);
    }
    else
    {
        return nullptr;
    }
}

Unit* RandGen::generateRandomEarthUnit(int timeStep) {
    uniform_int_distribution<> E_Power(EPower.start, EPower.end);
    uniform_int_distribution<> E_Health(EHealth.start, EHealth.end);
    uniform_int_distribution<> E_Capacity(EAttack.start, EAttack.end);

    int power = E_Power(gen);
    int health = E_Health(gen);
    int capacity = E_Capacity(gen);

    int B = getRandomNumber();

    if (B <= ESPercent) {
        return generateUnit(earthID++, timeStep, power, health, capacity, E_SOLDIER);
    } else if (B <= ESPercent + ETPercent) {
        return generateUnit(earthID++, timeStep, power, health, capacity, E_TANK);
    } else if (B <= ESPercent + ETPercent+ EGPercent){
        return generateUnit(earthID++, timeStep, power, health, capacity, E_GUNNERY);
    } else if (B <= ESPercent + ETPercent + EGPercent + HUPercent) { 
        return generateUnit(earthID++, timeStep, power, health, capacity, E_HEAL);
    } else {
        return nullptr;
    }
}

int RandGen::getRandomNumber() {
    // generates a random number from 1 to 100
    return Prob(gen);
}

void RandGen::setN(int n) { N = n; }
void RandGen::setESPercent(int percent) { ESPercent = percent; }
void RandGen::setETPercent(int percent) { ETPercent = percent; }
void RandGen::setEGPercent(int percent) { EGPercent = percent; }
void RandGen::setHUPercent(int percent) { HUPercent = percent; }

void RandGen::setASPercent(int percent) { ASPercent = percent; }
void RandGen::setAMPercent(int percent) { AMPercent = percent; }
void RandGen::setADPercent(int percent) { ADPercent = percent; }

void RandGen::setEPower(range power) { EPower = power; }
void RandGen::setEHealth(range health) { EHealth = health; }
void RandGen::setEAttack(range attack) { EAttack = attack; }

void RandGen::setAPower(range power) { APower = power; }
void RandGen::setAHealth(range health) { AHealth = health; }
void RandGen::setAAttack(range attack) { AAttack = attack; }
void RandGen::setGenerateProb(int prob) { generateProb = prob; }