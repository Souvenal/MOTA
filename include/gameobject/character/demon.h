#ifndef DEMON_H
#define DEMON_H

#include "gameobject/character/monster.h"

class Demon : public Monster
{
public:
    Demon(const Vector2D &position, const std::string &name = "Demon", GameObject *parent = nullptr);

protected:
    Renderer *renderer;
};

#endif // DEMON_H
