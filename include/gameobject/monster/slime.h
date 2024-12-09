#ifndef SLIME_H
#define SLIME_H

#include "gameobject/monster/monster.h"

class Slime : public Monster
{
public:
    Slime(const Vector2D &position, const std::string &name = "Slime", GameObject *parent = nullptr);

protected:
    Renderer *renderer;
};

#endif // SLIME_H
