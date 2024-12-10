#ifndef WARRIOR_H
#define WARRIOR_H

#include "gameobject/character/character.h"
#include "gameobject/ui/uitext.h"
#include "gameobject/battlemanager.h"
#include "gameobject/playerdatamanager.h"

#include "module/scenemanager.h"

class Warrior : public Character
{
public:

    int currentKeys;

public:
    Warrior(const Vector2D &position, const std::string &name = "Warrior", GameObject *parent = nullptr);

    void AddKeys(int keys);

    void Attack(Character *other, int turn) override;

    void StoreProperty();
    void RestoreProperty();

    void FixedUpdate() override;
    void Update() override;

    void OnCollisionEnter(Collider *other) override;

protected:
    Renderer *renderer;
};

#endif // WARRIOR_H
