#include "gameobject/item/potion.h"

Potion::Potion(const Vector2D &position, int healingAmount, const std::string &name, GameObject *parent):
    Item(position, name, parent), healingAmount(healingAmount)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/potion-ball.svg"));
}

void Potion::OnTriggerEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior *>(other->GetOwner());
    assert(warrior);
    warrior->Heal(healingAmount);

    SetActive(false);
}
