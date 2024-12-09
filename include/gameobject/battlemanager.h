#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include "gameobject/character.h"

class BattleManager : public GameObject_Impl
{
    static BattleManager *battleManager;

public:
    BattleManager(const std::string &name = "BattleManager", GameObject *parent = nullptr);

    static BattleManager* GetBattleManager();

    void StartBattle(Character *warrior, Character *monster);

    void Update() override;

private:
    Character *warrior;
    Character *monster;

    bool warriorTurn;

    void WarriorAttack();
    void MonsterAttack();
    void EndBattle();
};

#endif // BATTLEMANAGER_H
