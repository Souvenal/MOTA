#ifndef WEAPON_H
#define WEAPON_H

#include "gameobject/item/item.h"

class Weapon : public Item
{
private:
    int attack; // assigned in constructor

public:
    Weapon(const Vector2D &position, const std::string &name = "Weapon", GameObject *parent = nullptr);

    void OnTriggerEnter(Collider *other) override;

protected:

    Renderer *renderer;
};

#endif // WEAPON_H
