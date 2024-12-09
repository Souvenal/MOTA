#ifndef KEY_H
#define KEY_H

#include "gameobject/item/item.h"

class Key : public Item
{
public:
    Key(const Vector2D &position, const std::string &name = "Key", GameObject *parent = nullptr);

    void OnTriggerEnter(Collider *other) override;

protected:
    Renderer *renderer;
};

#endif // KEY_H
