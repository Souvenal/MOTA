#include "gameobject/tile/wall.h"

Wall::Wall(const Vector2D &position)
{
    boxCollider = AddComponent<BoxCollider>();
    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/brick-wall.svg"));
    transform->position = position;
}

void Wall::Start() {}

void Wall::Update() {}
