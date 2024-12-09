#include "gameobject/tile/lava.h"

Lava::Lava(const Vector2D &position, const std::string &name, GameObject* parent):
    Tile(position, name, parent)
{
    collider = AddComponent<BoxCollider>();
    collider->isTrigger = true;

    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/lava.svg"));
}

void Lava::OnTriggerEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    ApplyDamage(other);
}

void Lava::ApplyDamage(Collider *other)
{
    Warrior *warrior = dynamic_cast<Warrior*>(other->GetOwner());
    assert(warrior);

    warrior->TakeRealDamage(damage);
}
