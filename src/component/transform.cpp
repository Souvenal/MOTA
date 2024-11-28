#include "component/transform.h"

Transform::Transform(GameObject *owner):
    Component(owner)
{}

void Transform::Translate(const Vector2D &movement)
{
    position += movement;
}
