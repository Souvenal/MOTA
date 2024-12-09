#include "gameobject/tile/door.h"

Door::Door(const Vector2D &position, const std::string &name, GameObject *parent):
    Tile(position, name, parent)
{
    boxCollider = AddComponent<BoxCollider>();
    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/locked-door.svg"));
}

void Door::OnCollisionEnter(Collider *other)
{
    if (!other->CompareTag("Player"))
        return;

    Warrior *warrior = dynamic_cast<Warrior*>(other->GetOwner());
    assert(warrior);

    if (warrior->currentKeys > 0) {
        warrior->currentKeys--;
        SetActive(false);
    }
}
