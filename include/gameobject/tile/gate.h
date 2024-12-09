#ifndef GATE_H
#define GATE_H

#include "gameobject/tile/tile.h"

#include "gameobject/character/warrior.h"

#include "module/scenemanager.h"

class Gate : public Tile
{
public:
    Gate(const Vector2D &position, const std::string &target, const std::string &name = "Gate", GameObject* parent = nullptr);

protected:
    Collider *collider;
    Renderer *renderer;

    std::string target;

    void SetTarget(const std::string &target);

protected:
    void OnTriggerEnter(Collider *other) override;

private:
    void LoadTargetScene();
};

#endif // GATE_H
