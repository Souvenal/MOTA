#include "gameobject/battlemanager.h"

BattleManager* BattleManager::battleManager = nullptr;

BattleManager::BattleManager(const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent)
{}

BattleManager* BattleManager::GetBattleManager()
{
    if (!battleManager)
        battleManager = new BattleManager;
    return battleManager;
}

void BattleManager::StartBattle(Character *warrior, Character *monster)
{
    this->warrior = warrior;
    this->monster = monster;

    warriorTurn = true;

    qDebug() << "Battle between " << warrior->name << "and" << monster->name;
}

void BattleManager::Update()
{
    if (warrior && monster && warrior->IsActive() && monster->IsActive()) {
        if (warriorTurn) {
            WarriorAttack();
        }
        else {
            MonsterAttack();
        }

        warriorTurn = !warriorTurn; // switch turn
    }
    else {
        EndBattle();
    }
}

void BattleManager::WarriorAttack()
{
    warrior->Attack(monster);
}

void BattleManager::MonsterAttack()
{
    monster->Attack(warrior);
}

void BattleManager::EndBattle()
{
    warrior = nullptr;
    monster = nullptr;
}
