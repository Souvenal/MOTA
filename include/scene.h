#ifndef SCENE_H
#define SCENE_H

#include "component/renderer.h"
#include "gameobject/gameobject.h"
#include "physics.h"
#include "component/components.h"

#include <vector>

class Scene
{
    std::vector<GameObject*> gameObjects;
public:
    Scene();
    ~Scene();

    void AddGameObject(GameObject *gameObject);
    void Update();

    void Render(QPainter *painter);
};

#endif // SCENE_H
