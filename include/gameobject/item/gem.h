#ifndef GEM_H
#define GEM_H

#include "gameobject/item/item.h"

class Gem : public Item
{
private:
    int health; // assigned in constructor

    Renderer *renderer;

public:
    Gem(const Vector2D &position, const std::string &name = "Gem", GameObject *parent = nullptr);

    void OnTriggerEnter(Collider *other) override;
};

#endif // GEM_H
