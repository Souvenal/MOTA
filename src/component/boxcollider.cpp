#include "component/boxcollider.h"

BoxCollider::BoxCollider(GameObject *owner):
    Collider(owner)
{}

bool BoxCollider::CheckCollision(const Collider *other) const
{
    const BoxCollider *otherBox = dynamic_cast<const BoxCollider*>(other);
    if (otherBox) {
        return transform->position == other->transform->position;
    }
    return false;
}
