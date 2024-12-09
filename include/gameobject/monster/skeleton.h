#ifndef SKELETON_H
#define SKELETON_H

#include "gameobject/monster/monster.h"

class Skeleton : public Monster
{
public:
    Skeleton(const Vector2D &position, const std::string &name = "Skeleton", GameObject *parent = nullptr);

protected:
    Renderer *renderer;
};

#endif // SKELETON_H
