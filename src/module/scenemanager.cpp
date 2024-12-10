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
        scene = nullptr;
    }
}

SceneManager& SceneManager::GetSceneManager() {
    if (sceneManager == nullptr)
        sceneManager = new SceneManager;

    return *sceneManager;
}

void SceneManager::LoadScene()
{

    Scene *level1 = CreateLevel1();
    Scene *level2 = CreateLevel2();

    RegisterScene("Level1", level1);
    RegisterScene("Level2", level2);

    SetDefaultScene("Level1");

    SwitchScene(defaultMap);
}

void SceneManager::RegisterScene(const std::string &mapName, Scene *scene)
{
    sceneMap[mapName] = scene;
}

void SceneManager::SetDefaultScene(const std::string &mapName)
{
    defaultMap = mapName;
}

void SceneManager::SwitchScene(const std::string &mapName)
{
    currentScene = sceneMap[mapName];

    auto warrior = dynamic_cast<Warrior*>(currentScene->Find("Warrior"));
    assert(warrior);

    warrior->RestoreProperty();

    auto battleManager = dynamic_cast<BattleManager*>(currentScene->Find("BattleManager"));
    assert(battleManager);

    battleManager->SetDefault();
    connect(battleManager, &BattleManager::GameOver, this, &SceneManager::Send);
}

void SceneManager::RestartScene()
{
    for (auto &pair : sceneMap) {
        Scene *scene = pair.second;
        assert(scene);
        delete scene;
        scene = nullptr;
    }

    LoadScene();
}

void SceneManager::Update()
{
    auto warrior = dynamic_cast<Warrior*>(currentScene->Find("Warrior"));
    assert(warrior);

    if (!warrior->IsActive())
        RestartScene();

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

void SceneManager::Send(int coins)
{
    emit GameOver(coins);
}

