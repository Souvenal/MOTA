#include "module/scenemanager.h"

SceneManager* SceneManager::sceneManager = nullptr;

SceneManager::SceneManager()
{
    currentScene = nullptr;
}

SceneManager::~SceneManager()
{
    for (auto &pair : sceneMap) {
        Scene *scene = pair.second;
        delete scene;
    }
}

SceneManager& SceneManager::GetSceneManager() {
    if (sceneManager == nullptr)
        sceneManager = new SceneManager;

    return *sceneManager;
}

void SceneManager::RegisterScene(const std::string &mapName, Scene *scene)
{
    sceneMap[mapName] = scene;
}

void SceneManager::SwitchScene(const std::string &mapName)
{
    currentScene = sceneMap[mapName];

    auto warrior = dynamic_cast<Warrior*>(currentScene->Find("Warrior"));
    assert(warrior);


    warrior->RestoreProperty();
}

void SceneManager::Update()
{
    currentScene->Update();
}

void SceneManager::FixedUpdate()
{
    physicsSystem.FixedUpdate(currentScene->physicsObjects);
}

void SceneManager::Render(QPainter *painter)
{
    // render gameobjects
    renderSystem.Render(currentScene->renderers, painter);

    // render uiobjects
    for (const auto &uiObject : currentScene->uiObjects) {
        uiObject->Render(painter);
    }
}

