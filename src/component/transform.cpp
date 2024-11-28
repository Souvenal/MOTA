#include "component/transform.h"

Transform::Transform(GameObject_Interface *owner):
    Component(owner)
{}

void Transform::Translate(const Vector2D &movement)
{
    position += movement;
}
