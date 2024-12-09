#ifndef SCENE_H
#define SCENE_H

#include "gameobject/gameobject.hpp"
#include "gameobject/ui/uiobject.h"
#include "gameobject/character/warrior.h"

class Scene : public QObject
{
    Q_OBJECT

    friend class SceneManager;

public:

    void AddGameObject(GameObject *gameObject);
    void RemoveGameobject(GameObject *gameObject);
    GameObject* Find(const std::string &name) const;

    void Update();
    void FixedUpdate();
    void Render(QPainter *painter);

    Scene();
    ~Scene();

private:

    std::vector<GameObject*> gameObjects;
    std::vector<UIObject*> uiObjects;
    std::vector<GameObject*> physicsObjects; // transmit to physics system
    std::vector<Renderer*> renderers; // transmit to render system

private:

    void CollectRenderers(GameObject *gameObject);

    void CollectPhysicsObjects(GameObject *gameObject);

    void CollectUIObjects(GameObject *gameObject);
};

#endif // SCENE_H
