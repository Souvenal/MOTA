#ifndef TILE_H
#define TILE_H

#include "gameobject/gameobject_impl.h"

class Tile : public GameObject_Impl
{
public:
    Tile(const Vector2D &position, const std::string &name, GameObject* parent = nullptr);
};

#endif // TILE_H
