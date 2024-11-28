#ifndef COLLIDER_H
#define COLLIDER_H

#include "component/transform.h"

class Collider : public Component
{
    BAN_DEFAULT_CONSTURCTOR(Collider)

    friend class BoxCollider;

protected:
    Transform *transform;

public:

    bool isTrigger = false;

    Collider(GameObject *owner);

    virtual bool CheckCollision(const Collider *other) const = 0;

    void OnCollisionEnter(const Collider &other);
    void OnTriggerEnter(const Collider &other);
};

#endif // COLLIDER_H
