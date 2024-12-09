#include "gameobject/character/monster.h"

Monster::Monster(const Vector2D &position, const std::string &name, GameObject *parent):
    Character(name, parent)
{
    SetTag("Monster");

    transform->position = position;
}

void Monster::Attack(Character *other, int turn)
{
    if (!other->CompareTag("Player"))
        return;

    other->TakeDamage(attack);
}
