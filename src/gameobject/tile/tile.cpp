#include "gameobject/tile/tile.h"

Tile::Tile(const Vector2D &position, const std::string &name, GameObject* parent):
    GameObject_Impl(name, parent)
{
    transform->position = position;
}
