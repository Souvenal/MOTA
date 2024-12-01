#ifndef RIGIDBODY_H
#define RIGIDBODY_H

// #include "component/component.hpp"
#include "component/transform.h"

class RigidBody : public Component
{
    BAN_DEFAULT_CONSTURCTOR(RigidBody)

public:
    RigidBody(GameObject *owner);

    Vector2D velocity;
};

#endif // RIGIDBODY_H
