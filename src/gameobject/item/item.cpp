#include "gameobject/item/item.h"

Item::Item(const Vector2D &position, const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent)
{
    transform->position = std::move(position);

    collider = AddComponent<BoxCollider>();
    collider->isTrigger = true;
}
