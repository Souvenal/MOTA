#include "gameobject/wall.h"

Wall::Wall(const Vector2D &position)
{
    collider = AddComponent<Collider>();
    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/brick-wall.svg"));
    transform->position = position;
}

void Wall::Start() {}

void Wall::Update() {}
