#include "module/scene.h"

void Scene::AddGameObject(GameObject *gameObject)
{
    gameObjects.emplace_back(gameObject);

    RigidBody *rb = gameObject->GetComponent<RigidBody>();
    BoxCollider *collider = gameObject->GetComponent<BoxCollider>();
    if (rb || collider)
        physicsObjects.emplace_back(gameObject);

    SvgRenderer *renderer = gameObject->GetComponent<SvgRenderer>();
    if (renderer)
        renderers.emplace_back(renderer);
}

void Scene::RemoveGameobject(GameObject *gameObject)
{
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

void Scene::Update()
{
    for (const auto &gameObject : gameObjects) {
        gameObject->Update();
    }
}

void Scene::FixedUpdate()
{
    // qDebug() << "Fixed update";
    physicsSystem.FixedUpdate(physicsObjects);
}

void Scene::Render(QPainter *painter)
{
    renderSystem.Render(renderers, painter);
}

Scene::Scene()
{

}

Scene::~Scene()
{
    for (auto &gameObject : gameObjects)
        delete gameObject;
}
