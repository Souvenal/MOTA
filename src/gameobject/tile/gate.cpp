#include "gameobject/tile/gate.h"

Gate::Gate(const Vector2D &position, const std::string &target, const std::string &name, GameObject *parent):
    Tile(position, name, parent), target(target)
{
    collider = AddComponent<BoxCollider>();
    // collider->isTrigger = true;

    renderer = AddComponent<SvgRenderer>(QString(":/assets/images/dungeon-gate.svg"));
}

void Gate::SetTarget(const std::string &target)
{
    this->target = target;
}

void Gate::OnCollisionEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior*>(other->GetOwner());
    assert(warrior);

    warrior->StoreProperty();

    SceneManager::GetSceneManager().SwitchScene(target);
}
