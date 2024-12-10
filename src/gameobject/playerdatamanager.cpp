#include "gameobject/playerdatamanager.h"

static const int health_default = 50;
static const int attack_default = 20;
static const int defence_default = 5;
static const int coins_default = 0;
static const int keys_default = 0;

PlayerDataManager PlayerDataManager::manager;

PlayerDataManager::PlayerDataManager(const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent)
{
    Refresh();
}

PlayerDataManager& PlayerDataManager::GetInstance()
{
    return manager;
}

void PlayerDataManager::Refresh()
{
    currentHealth = maxHealth = health_default;
    attack = attack_default;
    defence = defence_default;
    coins = coins_default;
    keys = keys_default;
}
