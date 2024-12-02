#include "component/stats.h"

void Stats::TakeDamage(int damage)
{
    int finalDamage = std::max(damage - defence, 0);
    currentHealth -= finalDamage;
    qDebug() << "took " << finalDamage << " damage";

    if (currentHealth <= 0)
        Die();
}

void Stats::TakeRealDamage(int damage)
{
    currentHealth -= damage;
    qDebug() << "took " << damage << "real damage";

    if (currentHealth <= 0)
        Die();
}

void Stats::Die()
{
    qDebug() << "die";
    owner->SetActive(false);
}

Stats::Stats(GameObject *owner, int health, int attack, int defence):
    Component(owner), maxHealth(health), currentHealth(health),
    attack(attack), defence(defence)
{}
