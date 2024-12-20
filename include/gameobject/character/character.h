#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobject/gameobject_impl.h"

class Character : public GameObject_Impl
{
public:

    int maxHealth;
    int currentHealth;
    int attack;
    int defence;
    int coins;

    bool inBattle;

    bool spiritualPolluted;


public:

    Character(const std::string &name, GameObject *parent = nullptr);

    // @return: the damage dealt
    virtual int TakeDamage(int damage);

    // @return: the damage dealt
    virtual int TakeRealDamage(int damage);

    // @return: the health raised
    virtual int Heal(int healingAmount);

    virtual void Die();

    void RemoveDebuff();

    virtual void Attack(Character *other, int turn) = 0;

protected:
    Collider *collider;

    RigidBody *rb;
};

#endif // CHARACTER_H
