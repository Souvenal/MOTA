#include "gameobject/battlemanager.h"

BattleManager* BattleManager::battleManager = nullptr;

BattleManager::BattleManager(const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent), turn(0), inBattle(false)
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

    warrior->inBattle = true;
    monster->inBattle = true;

    inBattle = true;

    qDebug() << "Battle between " << warrior->name << "and" << monster->name << " ";
}

void BattleManager::Update()
{
    // no battle event
    if (!inBattle)
        return;

    assert(warrior);
    assert(monster);
    if (warrior->IsActive() && monster->IsActive()) {
        if (warriorTurn) {
            qDebug() << "turn" << ++turn << ":";
            WarriorAttack();
        }
        else {
            MonsterAttack();
        }

        warriorTurn = !warriorTurn; // switch turn
    }
    else {
        // post process
        if (warrior->IsActive()) {
            // warrior win
            warrior->coins += monster->coins;
        }
        else if (monster->IsActive()) {
            // monster win
        }
        EndBattle();
    }
}

void BattleManager::WarriorAttack()
{
    warrior->Attack(monster, turn);
}

void BattleManager::MonsterAttack()
{
    monster->Attack(warrior, turn);
}

void BattleManager::EndBattle()
{
    if (warrior)
        warrior->inBattle = false;
    if (monster)
        monster->inBattle = false;

    warrior = nullptr;
    monster = nullptr;

    turn = 0;
    inBattle = false;
}
