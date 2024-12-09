#include "gameobject/playerdatamanager.h"

PlayerDataManager PlayerDataManager::manager;

PlayerDataManager::PlayerDataManager(const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent)
{
    currentHealth = maxHealth = 50;
    attack = 20;
    defence = 5;
    coins = 0;
    keys = 0;
}

PlayerDataManager& PlayerDataManager::GetInstance()
{
    return manager;
}
