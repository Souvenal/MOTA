#include "gameobject/character/slime.h"

Slime::Slime(const Vector2D &position, const std::string &name, GameObject *parent):
    Monster(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/slime.svg"));

    currentHealth = maxHealth = 10;
    attack = 10;
    defence = 5;
    coins = 5;
}
