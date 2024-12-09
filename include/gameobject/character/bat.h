#ifndef BAT_H
#define BAT_H

#include "gameobject/character/monster.h"

class Bat : public Monster
{
public:
    Bat(const Vector2D &position, const std::string &name = "Bat", GameObject *parent = nullptr);

    void Attack(Character *other, int turn) override;

protected:
    Renderer *renderer;
};

#endif // BAT_H
