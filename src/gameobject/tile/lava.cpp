#include "gameobject/tile/lava.h"

Lava::Lava(const Vector2D &position, const std::string &name, GameObject* parent):
    Tile(position, name, parent)
{
    collider = AddComponent<BoxCollider>();
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/lava.svg"));
}
