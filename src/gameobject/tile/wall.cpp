#include "gameobject/tile/wall.h"

Wall::Wall(const Vector2D &position, const std::string &name, GameObject *parent):
    Tile(position, name, parent)
{
    boxCollider = AddComponent<BoxCollider>();
    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/brick-wall.svg"));
}
