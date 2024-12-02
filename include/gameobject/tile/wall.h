#ifndef WALL_H
#define WALL_H

#include "gameobject/tile/tile.h"

class Wall : public Tile
{
protected:
    BoxCollider *boxCollider;
    SvgRenderer *svgRenderer;

public:
    Wall(const Vector2D &position, const std::string &name, GameObject *parent = nullptr);
};

#endif // WALL_H
