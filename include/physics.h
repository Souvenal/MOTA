#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>

#include "component/rigidbody.h"
#include "component/collider.h"

class Physics
{
    static std::vector<RigidBody*> rigidBodies;
    static std::vector<Collider*> colliders;

public:
    static void Update();

    static void AddRigidBody(RigidBody *rb);
    static void AddCollider(Collider *collider);
};

#endif // PHYSICS_H
