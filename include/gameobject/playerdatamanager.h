#ifndef PLAYERDATAMANAGER_H
#define PLAYERDATAMANAGER_H

#include "gameobject/gameobject_impl.h"

class PlayerDataManager : public GameObject_Impl
{
public:
    PlayerDataManager(const std::string &name = "PlayerDataManager", GameObject *parent = nullptr);

    static PlayerDataManager& GetInstance();

    void Refresh();

    int currentHealth;
    int maxHealth;
    int attack;
    int defence;
    int coins;
    int keys;


private:

    static PlayerDataManager manager;
};

#endif // PLAYERDATAMANAGER_H
