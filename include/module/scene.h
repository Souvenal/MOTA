#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "component/renderer.h"
#include "gameobject/gameobject.hpp"
#include "component/components.h"
#include "module/physicssystem.h"
#include "module/rendersystem.h"

class Scene : public QObject
{
    Q_OBJECT

public:
    void AddGameObject(GameObject *gameObject);
    void RemoveGameobject(GameObject *gameObject);

    void Update();
    void FixedUpdate();
    void Render(QPainter *painter);

private:

    PhysicsSystem physicsSystem;

    RenderSystem renderSystem;

    std::vector<GameObject*> gameObjects;
    std::vector<GameObject*> physicsObjects; // transmit to physics system
    std::vector<Renderer*> renderers; // transmit to render system

public:
    Scene();
    ~Scene();
};

#endif // SCENE_H
