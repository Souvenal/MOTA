#ifndef WARRIOR_H
#define WARRIOR_H

#include "gameobject/character.h"
#include "gameobject/ui/uitext.h"
#include "gameobject/battlemanager.h"

class Warrior : public Character
{
public:

    int currentCoins;
    int currentKeys;

    bool debuff;

public:
    Warrior(const Vector2D &position, const std::string &name = "Warrior", GameObject *parent = nullptr);

    void AddCoins(int coins);
    void AddKeys(int keys);

    void Attack(Character *other) override;

    void FixedUpdate() override;
    void Update() override;

    void OnCollisionEnter(Collider *other) override;

protected:
    Renderer *renderer;
};

#endif // WARRIOR_H
