#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "component/collider.h"

class BoxCollider : public Collider
{
    BAN_DEFAULT_CONSTURCTOR(BoxCollider)

public:
    BoxCollider(GameObject* owner);

    bool CheckCollision(const Collider *other) const override;
};

#endif // BOXCOLLIDER_H
