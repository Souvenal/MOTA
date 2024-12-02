#ifndef WARRIORSTATS_H
#define WARRIORSTATS_H

#include "component/stats.h"

class WarriorStats : public Stats
{
    BAN_DEFAULT_CONSTURCTOR(WarriorStats)

public:
    int currentCoins;

public:
    void AddCoins(int coins);

    WarriorStats(GameObject *owner, int health, int attack, int defence, int coins);
};

#endif // WARRIORSTATS_H
