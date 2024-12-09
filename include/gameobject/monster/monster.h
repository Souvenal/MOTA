#ifndef MONSTER_H
#define MONSTER_H

#include "gameobject/character.h"

class Monster : public Character
{
public:
    int coins;

public:
    Monster(const Vector2D &position, const std::string &name, GameObject *parent = nullptr);

    virtual void Attack(Character *other) override;
};

#endif // MONSTER_H
