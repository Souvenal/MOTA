#ifndef WARRIOR_H
#define WARRIOR_H

#include "component/components.h"
#include "gameobject/gameobject_impl.h"
#include "gameobject/ui/uitext.h"

class Warrior : public GameObject_Impl
{
protected:
    BoxCollider *boxCollider;

    RigidBody *rb;

    SvgRenderer *svgRenderer;

    WarriorStats *stats;

public:
    Warrior(const Vector2D &position, const std::string &name, GameObject *parent = nullptr);

    void FixedUpdate() override;
    void Update() override;
};

#endif // WARRIOR_H
