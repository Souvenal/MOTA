#include "gameobject/character.h"

Character::Character(const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent)
{
    collider = AddComponent<BoxCollider>();

    rb = AddComponent<RigidBody>();
}

void Character::TakeDamage(int damage)
{
    int finalDamage = std::max(damage - defence, 0);
    currentHealth -= finalDamage;
    qDebug() << name << "took " << finalDamage << " damage";

    if (currentHealth <= 0)
        Die();
}

void Character::TakeRealDamage(int damage)
{
    currentHealth -= damage;
    qDebug() << name << "took " << damage << "real damage";

    if (currentHealth <= 0)
        Die();
}

void Character::Heal(int healingAmount)
{
    currentHealth = std::min(currentHealth + healingAmount, maxHealth);
}

void Character::Die()
{
    qDebug() << name << "die";

    SetActive(false);
}
