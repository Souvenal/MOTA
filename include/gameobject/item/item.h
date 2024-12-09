#ifndef ITEM_H
#define ITEM_H

#include "gameobject/gameobject_impl.h"

#include "gameobject/character/warrior.h"

class Item : public GameObject_Impl
{
public:
    Item(const Vector2D &position, const std::string &name, GameObject *parent = nullptr);

    virtual void OnTriggerEnter(Collider *other) = 0;

protected:
    Collider *collider;
};

#endif // ITEM_H
