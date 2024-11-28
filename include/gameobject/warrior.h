#ifndef WARRIOR_H
#define WARRIOR_H

#include "gameobject/gameobject.h"
#include "component/collider.h"
#include "component/svgrenderer.h"

class Warrior : public GameObject
{
protected:
    Collider *collider;
    SvgRenderer *svgRenderer;

public:
    Warrior(const Vector2D &position = Vector2D(0, 0));

    void Start();
    void Update();
};

#endif // WARRIOR_H
