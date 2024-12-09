#include "gameobject/monster/demon.h"

Demon::Demon(const Vector2D &position, const std::string &name, GameObject *parent):
    Monster(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/diablo-skull.svg"));

    currentHealth = maxHealth = 100;
    attack = 25;
    defence = 15;
    coins = 100;
}

