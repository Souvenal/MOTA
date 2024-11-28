#ifndef WALL_H
#define WALL_H

#include "gameobject/gameobject.h"
#include "component/collider.h"
#include "component/svgrenderer.h"

class Wall : public GameObject
{
protected:
    Collider *collider;
    SvgRenderer *svgRenderer;

public:
    Wall(const Vector2D &position = Vector2D(0, 0));

    void Start() override;
    void Update() override;
};

#endif // WALL_H
