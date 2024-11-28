#include "physics.h"

std::vector<RigidBody*> Physics::rigidBodies;
std::vector<Collider*> Physics::colliders;

void Physics::Update()
{

}

void Physics::AddRigidBody(RigidBody *rb)
{
    rigidBodies.emplace_back(rb);
}

void Physics::AddCollider(Collider *collider)
{
    colliders.emplace_back(collider);
}
