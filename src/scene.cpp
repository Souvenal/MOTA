#include "scene.h"

#include "gameobject/gameobject.h"

Scene::Scene() {}

Scene::~Scene()
{
    for (auto &gameObject : gameObjects)
        delete gameObject;
}

void Scene::AddGameObject(GameObject *gameObject)
{
    gameObjects.emplace_back(gameObject);
}


void Scene::Update()
{
    for (const auto &gameObject : gameObjects) {
        gameObject->Update();
    }
}

void Scene::Render(QPainter *painter) {
    // capture every renderer
    std::vector<Renderer *> renderers;
    for (const auto &gameObject : gameObjects) {
        SvgRenderer* svgRenderer = gameObject->GetComponent<SvgRenderer>();
        if (svgRenderer && svgRenderer->IsEnabled()) {
            renderers.emplace_back(svgRenderer);
        }
    }
    // render
    for (const auto &renderer : renderers) {
        renderer->Render(painter);
    }
}
