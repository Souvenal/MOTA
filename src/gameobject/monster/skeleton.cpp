#include "gameobject/monster/skeleton.h"

Skeleton::Skeleton(const Vector2D &position, const std::string &name, GameObject *parent):
    Monster(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/skeleton.svg"));

    currentHealth = maxHealth = 16;
    attack = 8;
    defence = 8;
    coins = 8;
}
