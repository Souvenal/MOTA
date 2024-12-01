#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H


#include "component/boxcollider.h"
#include "component/rigidbody.h"
#include "gameobject/gameobject.hpp"

class PhysicsSystem
{
public:
    void FixedUpdate(const std::vector<GameObject*> &physicsObjects);

private:
    void CallFixedUpdate();

    void UpdatePositions();

    void DetectCollisions();

    void ResolveCollisions();

    void ClearTemporaryData();

private:
    std::vector<GameObject*> physicsObjects;

    struct CollisionInfo {
        RigidBody *rb1;
        RigidBody *rb2;
        Collider *collider1;
        Collider *collider2;
    };
    std::vector<CollisionInfo> collisionList;
};


#endif // PHYSICSSYSTEM_H
