#include "gameobject/character/character.h"

Character::Character(const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent),
    inBattle(false), spiritualPolluted(false)
{
    collider = AddComponent<BoxCollider>();

    rb = AddComponent<RigidBody>();
}

// @return: the damage dealt
int Character::TakeDamage(int damage)
{
    int finalDamage = std::max(damage - defence, 0);
    int damageDealt = std::min(finalDamage, currentHealth);

    currentHealth -= finalDamage;
    qDebug() << name << "took " << damageDealt << " damage.";

    if (currentHealth <= 0)
        Die();

    return damageDealt;
}

// @return: the damage dealt
int Character::TakeRealDamage(int damage)
{
    int damageDealt = std::min(damage, currentHealth);
    currentHealth -= damage;
    qDebug() << name << "took " << damageDealt << " real damage.";

    if (currentHealth <= 0)
        Die();

    return damageDealt;
}

// @return: the health raised
int Character::Heal(int healingAmount)
{
    int healthRaised = std::min(healingAmount, maxHealth - currentHealth);
    currentHealth = std::min(currentHealth + healingAmount, maxHealth);

    qDebug() << name << "raised " << healthRaised << " health.";

    return healthRaised;
}

void Character::Die()
{
    qDebug() << name << "died.";

    SetActive(false);
}

void Character::RemoveDebuff()
{
    spiritualPolluted = false;
}
