#ifndef WARRIOR_H
#define WARRIOR_H

#include "gameobject/gameobject_impl.h"
#include "component/components.h"

class Warrior : public GameObject_Impl
{
protected:
    BoxCollider *boxCollider;

    RigidBody *rb;

    SvgRenderer *svgRenderer;

    Stats *stats;

public:
    Warrior(const Vector2D &position = Vector2D(0, 0));

    void FixedUpdate() override;
    void Update() override;
};

#endif // WARRIOR_H
