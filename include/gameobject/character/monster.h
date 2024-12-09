#ifndef MONSTER_H
#define MONSTER_H

#include "gameobject/character/character.h"

class Monster : public Character
{
public:
    Monster(const Vector2D &position, const std::string &name, GameObject *parent = nullptr);

    virtual void Attack(Character *other, int turn) override;
};

#endif // MONSTER_H
