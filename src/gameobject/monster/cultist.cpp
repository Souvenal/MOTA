#include "gameobject/monster/cultist.h"

Cultist::Cultist(const Vector2D &position, const std::string &name, GameObject *parent):
    Monster(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/cultist.svg"));

    currentHealth = maxHealth = 50;
    attack = 30;
    defence = 15;
    coins = 25;
}

