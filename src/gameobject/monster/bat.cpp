#include "gameobject/monster/bat.h"

Bat::Bat(const Vector2D &position, const std::string &name, GameObject *parent):
    Monster(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/bat.svg"));

    currentHealth = maxHealth = 25;
    attack = 15;
    defence = 0;
    coins = 10;
}
