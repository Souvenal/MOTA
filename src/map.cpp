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
        std::string str1 = std::to_string(1) + "_" + std::to_string(j);
        std::string str2 = std::to_string(COL_NUM) + "_" + std::to_string(j);
        map->AddGameObject(new Wall(Vector2D(1, j), str1));
        map->AddGameObject(new Wall(Vector2D(COL_NUM, j), str2));
    }

    Warrior* warrior = new Warrior(Vector2D(7, 3), "Warrior");
    map->AddGameObject(new UIText(
        QRectF(0, 0, 200, 30), QString(warrior->name.c_str()),
        QFont("Arial", 30, QFont::Bold), QColorConstants::Svg::darkorange,
        "NameText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 30, 200, 30), QStringLiteral("Attack:"),
        QFont("Arial", 30, QFont::Bold), QColorConstants::Svg::darkorange,
        "AttackText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 60, 200, 30), QStringLiteral("Defence:"),
        QFont("Arial", 30, QFont::Bold), QColorConstants::Svg::darkorange,
        "DefenceText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 90, 200, 30), QStringLiteral("Health:"),
        QFont("Arial", 30, QFont::Bold), QColorConstants::Svg::darkorange,
        "HealthText", warrior));
    map->AddGameObject(new UIText(
        QRectF(0, 120, 200, 30), QStringLiteral("Coins:"),
        QFont("Arial", 30, QFont::Bold), QColorConstants::Svg::darkorange,
        "CoinsText", warrior));

    map->AddGameObject(warrior);

    return map;
}
