#ifndef CULTIST_H
#define CULTIST_H

#include "gameobject/monster/monster.h"

class Cultist : public Monster
{
public:
    Cultist(const Vector2D &position, const std::string &name = "Cultist", GameObject *parent = nullptr);

protected:
    Renderer *renderer;
};

#endif // CULTIST_H
