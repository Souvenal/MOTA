#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>

#include "component/components.h"

#include "gameobject/gameobject.hpp"
#include "gameobject/character/warrior.h"
#include "gameobject/character/demon.h"

#include "module/scene.h"
#include "module/physicssystem.h"
#include "module/rendersystem.h"

#include "map.h"

class SceneManager : public QObject
{
    Q_OBJECT

public:
    explicit SceneManager();

    ~SceneManager();

    static SceneManager& GetSceneManager();

    void LoadScene();
    void RegisterScene(const std::string &mapName, Scene *scene);
    void SetDefaultScene(const std::string &mapName);

    void SwitchScene(const std::string &mapName);

    void RestartScene();

    void Update();
    void FixedUpdate();
    void Render(QPainter *painter);

private:

    static SceneManager* sceneManager;

    std::string defaultMap;

    std::unordered_map<std::string, Scene*> sceneMap;

    Scene *currentScene;

    /* control module */
    PhysicsSystem physicsSystem;

    RenderSystem renderSystem;

    QWidget *widget;

private slots:
    void Send(int coins);

signals:
    void GameOver(int coins);
};

#endif // SCENEMANAGER_H
