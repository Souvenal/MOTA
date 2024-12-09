#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "component/components.h"

#include "gameobject/gameobject.hpp"

#include "module/scene.h"
#include "module/physicssystem.h"
#include "module/rendersystem.h"

class SceneManager
{
public:
    explicit SceneManager();

    ~SceneManager();

    static SceneManager& GetSceneManager();

    void RegisterScene(const std::string &mapName, Scene *scene);

    void SwitchScene(const std::string &mapName);

    void Update();
    void FixedUpdate();
    void Render(QPainter *painter);

private:

    static SceneManager* sceneManager;

    std::unordered_map<std::string, Scene*> sceneMap;

    Scene *currentScene;

    /* control module */
    PhysicsSystem physicsSystem;

    RenderSystem renderSystem;

    QWidget *widget;


};

#endif // SCENEMANAGER_H
