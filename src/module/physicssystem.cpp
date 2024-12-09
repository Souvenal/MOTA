#include "module/physicssystem.h"

void PhysicsSystem::FixedUpdate(const std::vector<GameObject*> &physicsObjects)
{
    this->physicsObjects = physicsObjects;

    CallFixedUpdate();

    UpdatePositions();

    DetectCollisions();

    ResolveCollisions();

    TriggerPhysicsEvents();

    ClearTemporaryData();
}

void PhysicsSystem::CallFixedUpdate()
{
    for (auto &physicsObject : physicsObjects) {
        if (physicsObject->IsActive())
            physicsObject->FixedUpdate();
    }
}


void PhysicsSystem::UpdatePositions()
{
    // qDebug() << "Updating positions.";
    for (auto &physicsObject : physicsObjects) {
        if (!physicsObject->IsActive())
            continue;

        Transform *transform = physicsObject->GetComponent<Transform>();
        RigidBody *rb = physicsObject->GetComponent<RigidBody>();
        if (rb)
            transform->position = transform->position + rb->velocity;
    }
}

void PhysicsSystem::DetectCollisions()
{
    std::vector<Collider*> colliders;
    for (const auto &physicsObject : physicsObjects) {
        if (!physicsObject->IsActive())
            continue;

        auto *collider = physicsObject->GetComponent<BoxCollider>();
        if (collider) {
            colliders.emplace_back(collider);
        }
    }

    for (int i = 0; i < colliders.size(); i++) {
        for (int j = i + 1; j < colliders.size(); j++) {
            if (colliders[i]->CheckCollision(colliders[j])) {
                RigidBody *rb1 = colliders[i]->GetComponent<RigidBody>();
                RigidBody *rb2 = colliders[j]->GetComponent<RigidBody>();
                CollisionInfo info = {rb1, rb2, colliders[i], colliders[j]};
                collisionList.emplace_back(info);
            }
        }
    }
}

void PhysicsSystem::ResolveCollisions()
{
    // call OnCollisionEnter events
    for (auto &info : collisionList) {
        bool enter = (find(previousList.begin(), previousList.end(), info) == previousList.end());
        if (enter) {
            if (info.rb1 && !info.collider2->isTrigger) {
                info.collider2->GetOwner()->OnCollisionEnter(info.collider1);
            }
            if (info.rb2 && !info.collider1->isTrigger) {
                info.collider1->GetOwner()->OnCollisionEnter(info.collider2);
            }
        }
    }

    for (auto &info : collisionList) {
        if (info.rb1 && !info.collider2->isTrigger) {
            Transform *transform = info.rb1->GetComponent<Transform>();
            transform->position = transform->position - info.rb1->velocity;
        }
        if (info.rb2 && !info.collider1->isTrigger) {
            Transform *transform = info.rb2->GetComponent<Transform>();
            transform->position = transform->position - info.rb2->velocity;
        }
    }
}

void PhysicsSystem::TriggerPhysicsEvents()
{
    for (auto &info : collisionList) {
        bool enter = (find(previousList.begin(), previousList.end(), info) == previousList.end());
        if (enter) {
            if (info.rb1 && info.collider2->isTrigger) {
                info.collider2->GetOwner()->OnTriggerEnter(info.collider1);
            }
            if (info.rb2 && info.collider1->isTrigger) {
                info.collider1->GetOwner()->OnTriggerEnter(info.collider2);
            }
        }
    }
}

void PhysicsSystem::ClearTemporaryData()
{
    // remove velocity
    // qDebug() << "removing velovity.";
    for (auto &physicsObject : physicsObjects) {
        if (!physicsObject->IsActive())
            continue;

        RigidBody *rb = physicsObject->GetComponent<RigidBody>();
        if (rb)
            rb->velocity = Vector2D(0, 0);
    }
    physicsObjects.clear();
    previousList = std::move(collisionList);
    collisionList.clear();
}

bool PhysicsSystem::CollisionInfo::operator== (const CollisionInfo &other)
{
    return rb1 == other.rb1 && rb2 == other.rb2
           && collider1 == other.collider1 && collider2 == other.collider2;
}
