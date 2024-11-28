#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "component/component.h"
#include "vector2d.h"

class Transform : public Component
{
    BAN_DEFAULT_CONSTURCTOR(Transform)

public:
    Vector2D position = Vector2D(0, 0);
    Vector2D rotation = Vector2D(0, 0);
    Vector2D scale = Vector2D(1.0, 1.0);

public:
    Transform(GameObject_Interface *owner);

    void Translate(const Vector2D &movement);
};

#endif // TRANSFORM_H
