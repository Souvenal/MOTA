#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <QObject>

#include "gameobject/character/character.h"

class BattleManager : public QObject, public GameObject_Impl
{
    Q_OBJECT

    static BattleManager *battleManager;

    int turn;

    bool inBattle;

public:
    BattleManager(const std::string &name = "BattleManager", GameObject *parent = nullptr);

    static BattleManager* GetBattleManager();

    void StartBattle(Character *warrior, Character *monster);

    void SetDefault();

    void Update() override;

private:
    Character *warrior;
    Character *monster;

    bool warriorTurn;

    void WarriorAttack();
    void MonsterAttack();
    void EndBattle();

signals:
    void GameOver(int coins);
};

#endif // BATTLEMANAGER_H
