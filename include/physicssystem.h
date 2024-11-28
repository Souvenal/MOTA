#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "component/boxcollider.h"
#include "component/rigidbody.h"
#include "gameobject/gameobject.hpp"

class PhysicsSystem {
public:
    void FixedUpdate(const std::vector<GameObject*> &gameObjects);

private:
    void CollectPhysicsObjects(const std::vector<GameObject*> &gameObjects);
    void DetectCollisions(const std::vector<GameObject*> &gameObjects);
    void ClearTemporaryData();

    std::vector<GameObject*> physicsObjects;
};


#endif // PHYSICSSYSTEM_H
