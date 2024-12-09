#include "gameobject/item/armor.h"

Armor::Armor(const Vector2D &position, const std::string &name, GameObject *parent):
    Item(position, name, parent), defence(10)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/armor.svg"));
}

void Armor::OnTriggerEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior *>(other->GetOwner());
    assert(warrior);
    warrior->defence += defence;

    SetActive(false);
}
