#include "physicssystem.h"

void PhysicsSystem::FixedUpdate(const std::vector<GameObject*> &gameObjects)
{
    CollectPhysicsObjects(gameObjects);

    // // 2. 应用外力
    // for (auto& rb : rigidbodies) {
    //     ApplyForces(rb);
    // }

    // 3. 碰撞检测
    //DetectCollisions();

    // 4. 碰撞响应
    //ResolveCollisions();

    // 5. 更新位置
    // for (auto& rb : rigidbodies) {
    //     UpdatePositions(rb);
    // }

    // 6. 后处理
    // TriggerPhysicsEvents();
    // ClearTemporaryData();
}

void PhysicsSystem::CollectPhysicsObjects(const std::vector<GameObject*> &gameObjects)
{
    for (const auto &gameObject : gameObjects) {
        RigidBody *rb = gameObject->GetComponent<RigidBody>();
        BoxCollider *boxCollider = gameObject->GetComponent<BoxCollider>();
        if (rb || boxCollider) {
            physicsObjects.emplace_back(gameObject);
        }
    }
}

void PhysicsSystem::DetectCollisions(const std::vector<GameObject*> &gameObjects)
{
    // capture every collider
    std::vector<Collider*> colliders;
    for (const auto &gameObject : gameObjects) {
        auto *collider = gameObject->GetComponent<BoxCollider>();
        if (collider) {
            colliders.emplace_back(collider);
        }
    }

    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            colliders[i]->CheckCollision(colliders[j]);
        }
    }
}

void PhysicsSystem::ClearTemporaryData()
{
    physicsObjects.clear();
}
