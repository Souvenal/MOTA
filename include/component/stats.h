#ifndef STATS_H
#define STATS_H

#include "component/component.hpp"

class Stats : public Component
{
    BAN_DEFAULT_CONSTURCTOR(Stats)

public:
    int maxHealth;
    int currentHealth;
    int attack;
    int defence;

public:

    void TakeDamage(int damage);

    void Die();

    Stats(GameObject *owner, int health, int attack, int defence);
};

#endif // STATS_H
