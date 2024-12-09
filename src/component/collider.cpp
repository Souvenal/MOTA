#include "component/collider.h"

Collider::Collider(GameObject *owner):
    Component(owner), isTrigger(false)
{
    transform = GetComponent<Transform>();
}
