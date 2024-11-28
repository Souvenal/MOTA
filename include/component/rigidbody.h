#ifndef RIGIDBODY_H
#define RIGIDBODY_H

// #include "component/component.hpp"
#include "component/transform.h"

class RigidBody : public Component
{
    BAN_DEFAULT_CONSTURCTOR(RigidBody)

protected:
    Vector2D velocity;

public:
    RigidBody(GameObject *owner);
};

#endif // RIGIDBODY_H
