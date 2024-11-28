#include "component/rigidbody.h"

RigidBody::RigidBody(GameObject *owner):
    Component(owner), velocity(Vector2D(0, 0))
{

}
