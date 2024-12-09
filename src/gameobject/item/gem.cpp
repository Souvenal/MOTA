#include "gameobject/item/gem.h"

Gem::Gem(const Vector2D &position, const std::string &name, GameObject *parent):
    Item(position, name, parent), health(50)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/mineral-heart.svg"));
}

void Gem::OnTriggerEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior *>(other->GetOwner());
    assert(warrior);
    warrior->currentHealth += health;
    warrior->maxHealth += health;

    SetActive(false);
}
