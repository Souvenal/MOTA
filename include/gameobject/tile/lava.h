#ifndef LAVA_H
#define LAVA_H

#include "gameobject/tile/tile.h"

class Lava : public Tile
{
public:
    Lava(const Vector2D &position, const std::string &name, GameObject* parent = nullptr);

protected:
    BoxCollider *collider;
    SvgRenderer *renderer;
};

#endif // LAVA_H
