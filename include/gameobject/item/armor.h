#ifndef ARMOR_H
#define ARMOR_H

#include "gameobject/item/item.h"

class Armor : public Item
{
private:
    int defence; // assigned in constructor

    Renderer *renderer;

public:
    Armor(const Vector2D &position, const std::string &name = "Armor", GameObject *parent = nullptr);

protected:
    void OnTriggerEnter(Collider *other) override;
};

#endif // ARMOR_H
