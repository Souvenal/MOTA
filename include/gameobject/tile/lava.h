#ifndef LAVA_H
#define LAVA_H

#include "gameobject/tile/tile.h"

#include "gameobject/warrior.h"

class Lava : public Tile
{
private:
    int damage = 10;

    BoxCollider *collider;
    SvgRenderer *renderer;

public:
    Lava(const Vector2D &position, const std::string &name, GameObject* parent = nullptr);

protected:
    void OnTriggerEnter(Collider *other) override;

private:
    void ApplyDamage(Collider *other);
};

#endif // LAVA_H
