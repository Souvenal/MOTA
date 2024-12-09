#include "gameobject/character/cultist.h"

Cultist::Cultist(const Vector2D &position, const std::string &name, GameObject *parent):
    Monster(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/cultist.svg"));

    currentHealth = maxHealth = 50;
    attack = 30;
    defence = 15;
    coins = 25;
}

void Cultist::Attack(Character *other, int turn)
{
    if (!other->CompareTag("Player"))
        return;

    if (turn % 3 == 2) {
        other->spiritualPolluted = true;
    }
    other->TakeDamage(attack);
}
