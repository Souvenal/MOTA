#ifndef SCENE_H
#define SCENE_H

#include "component/renderer.h"
#include "gameobject/gameobject_impl.h"
#include "component/components.h"
#include "physicssystem.h"
#include <vector>

class Scene
{
    PhysicsSystem physicsSystem;
    std::vector<GameObject*> gameObjects;

public:
    Scene();
    ~Scene();

    void AddGameObject(GameObject *gameObject);
    void RemoveGameobject(GameObject *gameObject);

    void FixedUpdate();

    void Update();
    void Render(QPainter *painter);
};

#endif // SCENE_H
