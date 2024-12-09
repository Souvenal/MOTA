#include "gameobject/item/key.h"

Key::Key(const Vector2D &position, const std::string &name, GameObject *parent):
    Item(position, name, parent)
{
    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/key.svg"));
}

void Key::OnTriggerEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior *>(other->GetOwner());
    assert(warrior);
    warrior->AddKeys(1);

    SetActive(false);
}
