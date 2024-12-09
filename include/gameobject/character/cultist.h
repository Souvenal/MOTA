#ifndef CULTIST_H
#define CULTIST_H

#include "gameobject/character/monster.h"

class Cultist : public Monster
{
public:
    Cultist(const Vector2D &position, const std::string &name = "Cultist", GameObject *parent = nullptr);

    void Attack(Character *other, int turn) override;

protected:
    Renderer *renderer;
};

#endif // CULTIST_H
