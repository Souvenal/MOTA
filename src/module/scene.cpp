#include "module/scene.h"


void Scene::AddGameObject(GameObject *gameObject)
{
    gameObjects.emplace_back(gameObject);

    CollectUIObjects(gameObject);

    CollectPhysicsObjects(gameObject);

    CollectRenderers(gameObject);
}

void Scene::RemoveGameobject(GameObject *gameObject)
{
    // Destroy
    gameObjects.erase(
        std::remove(gameObjects.begin(), gameObjects.end(), gameObject),
        gameObjects.end()
    );
    physicsObjects.erase(
        std::remove(physicsObjects.begin(), physicsObjects.end(), gameObject),
        physicsObjects.end()
    );
    delete gameObject;
}

GameObject* Scene::Find(const std::string &name) const
{
    for (GameObject* gameobject : gameObjects) {
        if (gameobject->name == name)
            return gameobject;
    }

    return nullptr;
}

void Scene::Update()
{
    for (const auto &gameObject : gameObjects) {
        if (gameObject->IsActive())
            gameObject->Update();
    }
}

Scene::Scene()
{

}

Scene::~Scene()
{
    for (auto &gameObject : gameObjects) {
        if (dynamic_cast<BattleManager*>(gameObject))
            continue;
        delete gameObject;
        gameObject = nullptr;
    }
}

void Scene::CollectPhysicsObjects(GameObject *gameObject)
{
    RigidBody *rb = gameObject->GetComponent<RigidBody>();
    BoxCollider *collider = gameObject->GetComponent<BoxCollider>();
    if (rb || collider)
        physicsObjects.emplace_back(gameObject);
}

void Scene::CollectUIObjects(GameObject *gameObject)
{
    UIObject* uiObject = dynamic_cast<UIObject*>(gameObject);
    if (uiObject) {
        uiObjects.emplace_back(uiObject);
    }
}

void Scene::CollectRenderers(GameObject *gameObject)
{
    SvgRenderer *svgRenderer = gameObject->GetComponent<SvgRenderer>();
    if (svgRenderer) {
        renderers.emplace_back(svgRenderer);
        return;
    }
    CanvasRenderer *canvasRenderer = gameObject->GetComponent<CanvasRenderer>();
    if (canvasRenderer) {
        renderers.emplace_back(canvasRenderer);
        return;
    }
}
