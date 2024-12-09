#ifndef BAT_H
#define BAT_H

#include "gameobject/monster/monster.h"

class Bat : public Monster
{
public:
    Bat(const Vector2D &position, const std::string &name = "Bat", GameObject *parent = nullptr);

protected:
    Renderer *renderer;
};

#endif // BAT_H
