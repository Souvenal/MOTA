#include "gameobject/item/weapon.h"

Weapon::Weapon(const Vector2D &position, const std::string &name, GameObject *parent):
    Item(position, name, parent), attack(20)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/sword-altar.svg"));
}

void Weapon::OnTriggerEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior *>(other->GetOwner());
    assert(warrior);
    warrior->attack += attack;

    SetActive(false);
}
