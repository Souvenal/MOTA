#include "component/warriorstats.h"

void WarriorStats::AddCoins(int coins) { currentCoins += coins; }

WarriorStats::WarriorStats(GameObject *owner, int health, int attack, int defence, int coins):
    Stats(owner, health, attack, defence), currentCoins(coins)
{}
