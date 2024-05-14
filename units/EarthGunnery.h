#pragma once

#include "Unit.h"

class EarthGunnery : public Unit {
   public:
    EarthGunnery(int ID, int timeStep, int health, int power,
                 int attackCapacity, const Game* game);

    int getPriority() const;

    void attack(int timeStep, Mode operation) override;
};