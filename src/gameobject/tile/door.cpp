#include "gameobject/tile/door.h"

Door::Door(const Vector2D &position, const std::string &name, GameObject *parent):
    Tile(position, name, parent)
{
    boxCollider = AddComponent<BoxCollider>();
    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/locked-door.svg"));
}
