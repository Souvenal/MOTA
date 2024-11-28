#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "component/component.h"

class RigidBody : public Component
{
    BAN_DEFAULT_CONSTURCTOR(RigidBody)

public:
    RigidBody(GameObject_Interface *owner);
};

#endif // RIGIDBODY_H
