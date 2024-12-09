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

public:

    Character(const std::string &name, GameObject *parent = nullptr);

    void TakeDamage(int damage);

    void TakeRealDamage(int damage);

    void Heal(int healingAmount);

    void Die();

    virtual void Attack(Character *other) = 0;

protected:
    Collider *collider;

    RigidBody *rb;
};

#endif // CHARACTER_H
