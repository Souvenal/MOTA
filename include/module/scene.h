#ifndef SCENE_H
#define SCENE_H

#include <QWidget>

#include "component/components.h"

#include "gameobject/gameobject.hpp"
#include "gameobject/ui/uiobject.h"

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

    Scene();
    ~Scene();

private:

    PhysicsSystem physicsSystem;

    RenderSystem renderSystem;

    std::vector<GameObject*> gameObjects;
    std::vector<UIObject*> uiObjects;
    std::vector<GameObject*> physicsObjects; // transmit to physics system
    std::vector<Renderer*> renderers; // transmit to render system

    QWidget *widget;

private:

    void CollectRenderers(GameObject *gameObject);

    void CollectPhysicsObjects(GameObject *gameObject);

    void CollectUIObjects(GameObject *gameObject);
};

#endif // SCENE_H
