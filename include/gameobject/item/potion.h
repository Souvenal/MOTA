#ifndef POSION_H
#define POSION_H

#include "gameobject/item/item.h"

class Potion : public Item
{
private:
    int healingAmount; // assigned in constructor, default 10

public:
    Potion(const Vector2D &position, int healingAmount = 10, const std::string &name = "Potion", GameObject *parent = nullptr);

    void OnTriggerEnter(Collider *other) override;

protected:

    Renderer *renderer;
};

#endif // POSION_H
