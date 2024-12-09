#include "global.h"
#include "module/scene.h"
#include "gameobject/gameobjects.h"

Scene* CreateMap1()
{
    Scene *map = new Scene;


    for (int i = 1; i <= COL_NUM; i++) {
        std::string str1 = "Wall" + std::to_string(i) + "_" + std::to_string(1);
        std::string str2 = "Wall" + std::to_string(i) + "_" + std::to_string(ROW_NUM);
        map->AddGameObject(new Wall(Vector2D(i, 1), str1));
        map->AddGameObject(new Wall(Vector2D(i, ROW_NUM), str2));
    }
    for (int j = 2; j < ROW_NUM; j++) {
        std::string str1 = "Wall" + std::to_string(1) + "_" + std::to_string(j);
        std::string str2 = "Wall" + std::to_string(COL_NUM) + "_" + std::to_string(j);
        map->AddGameObject(new Wall(Vector2D(1, j), str1));
        map->AddGameObject(new Wall(Vector2D(COL_NUM, j), str2));
    }

    map->AddGameObject(new Lava(Vector2D(2, 12), "Lava"));

    map->AddGameObject(new Door(Vector2D(7, 6), "Door"));

    map->AddGameObject(BattleManager::GetBattleManager());

    Warrior* warrior = new Warrior(Vector2D(7, 4), "Warrior");
    map->AddGameObject(new UIText(
        QRectF(0, 0, 200, 25), QString(warrior->name.c_str()),
        QFont("Arial", 25, QFont::Bold), QColorConstants::Svg::darkorange,
        "NameText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 25, 200, 25), QStringLiteral("Attack:"),
        QFont("Arial", 25, QFont::Bold), QColorConstants::Svg::darkorange,
        "AttackText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 50, 200, 25), QStringLiteral("Defence:"),
        QFont("Arial", 25, QFont::Bold), QColorConstants::Svg::darkorange,
        "DefenceText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 75, 200, 25), QStringLiteral("Health:"),
        QFont("Arial", 25, QFont::Bold), QColorConstants::Svg::darkorange,
        "HealthText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 100, 200, 25), QStringLiteral("Coins:"),
        QFont("Arial", 25, QFont::Bold), QColorConstants::Svg::darkorange,
        "CoinsText", warrior));

    map->AddGameObject(warrior);

    map->AddGameObject(new Armor(Vector2D(3, 2)));
    map->AddGameObject(new Gem(Vector2D(5, 2)));
    map->AddGameObject(new Potion(Vector2D(7, 2)));
    map->AddGameObject(new Weapon(Vector2D(9, 2)));
    map->AddGameObject(new Key(Vector2D(11, 2)));

    map->AddGameObject(new Slime(Vector2D(3, 8)));
    map->AddGameObject(new Skeleton(Vector2D(5, 8)));
    map->AddGameObject(new Bat(Vector2D(7, 8)));
    map->AddGameObject(new Cultist(Vector2D(9, 8)));
    map->AddGameObject(new Demon(Vector2D(11, 8)));


    return map;
}
