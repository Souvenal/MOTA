#ifndef DOOR_H
#define DOOR_H

#include "gameobject/tile/tile.h"

class Door : public Tile
{
public:
    Door(const Vector2D &position, const std::string &name, GameObject* parent = nullptr);

protected:
    BoxCollider *boxCollider;
    SvgRenderer *svgRenderer;
};

#endif // DOOR_H
