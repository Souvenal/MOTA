#include "global.h"
#include "module/scene.h"
#include "gameobject/gameobjects.h"

make_add_func(Wall)
make_add_func(Door)
make_add_func(Lava)

make_add_func(Slime)
make_add_func(Skeleton)
make_add_func(Bat)
make_add_func(Cultist)
make_add_func(Demon)

make_add_func(Armor)
make_add_func(Gem)
make_add_func(Key)
make_add_func(Potion)
make_add_func(Weapon)

void AddWarrior(Scene *map, const Vector2D &pos)
{
    Warrior* warrior = new Warrior(pos, "Warrior");
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
}

void AddNecessary(Scene *map)
{
    map->AddGameObject(BattleManager::GetBattleManager());

    map->AddGameObject(new Manual(QRect(200, 100, 400, 200)));
}

Scene* CreateLevel1()
{
    Scene *map = new Scene;

    AddWarrior(map, Vector2D(7, 3));

    AddNecessary(map);


    // all tiles
    std::vector<Vector2D> pos_wall = {
        Vector2D(2, 5), Vector2D(2, 8), Vector2D(4, 5), Vector2D(4, 8), Vector2D(6, 4), Vector2D(7, 6),
        Vector2D(7, 8), Vector2D(7, 9), Vector2D(7, 10), Vector2D(8, 4), Vector2D(8, 6), Vector2D(8, 8),
        Vector2D(9, 2), Vector2D(9, 3), Vector2D(9, 4), Vector2D(9, 6), Vector2D(9, 8), Vector2D(10, 4),
        Vector2D(10, 6), Vector2D(12, 4)
    };
    for (int i = 2; i <= 11; i++) pos_wall.emplace_back(Vector2D(i, 11));
    for (int j = 2; j <= 9; j++) pos_wall.emplace_back(Vector2D(5, j));
    for (int j = 6; j <= 10; j++) pos_wall.emplace_back(Vector2D(11, j));
    for (int i = 1; i <= COL_NUM; i++) {
        pos_wall.emplace_back(Vector2D(i, 1));
        pos_wall.emplace_back(Vector2D(i, ROW_NUM));
    }
    for (int j = 2; j < ROW_NUM; j++) {
        pos_wall.emplace_back(Vector2D(1, j));
        pos_wall.emplace_back(Vector2D(COL_NUM, j));
    }
    std::vector<Vector2D> pos_lava;
    std::vector<Vector2D> pos_door = {
        Vector2D(3, 5), Vector2D(3, 8), Vector2D(5, 10), Vector2D(7, 4), Vector2D(7, 7), Vector2D(11, 4),
    };

    AddWall(map, pos_wall);
    AddLava(map, pos_lava);
    AddDoor(map, pos_door);

    map->AddGameObject(new Gate(Vector2D(2, 12), "Level2"));


    // all monsters
    std::vector<Vector2D> pos_slime = {
        Vector2D(5, 12), Vector2D(6, 12), Vector2D(7, 12), Vector2D(9, 7), Vector2D(10, 8)
    };
    std::vector<Vector2D> pos_skeleton = {
        Vector2D(3, 4), Vector2D(3, 7), Vector2D(3, 9), Vector2D(4, 10)
    };
    std::vector<Vector2D> pos_bat = {Vector2D(10, 7)};
    std::vector<Vector2D> pos_cultist = {Vector2D(8, 7), Vector2D(11, 3)};
    std::vector<Vector2D> pos_demon = {};

    AddSlime(map, pos_slime);
    AddSkeleton(map, pos_skeleton);
    AddBat(map, pos_bat);
    AddCultist(map, pos_cultist);
    AddDemon(map, pos_demon);


    // all items
    std::vector<Vector2D> pos_armor = {
        Vector2D(2, 6)
    };
    std::vector<Vector2D> pos_gem = {
        Vector2D(4, 9)
    };
    std::vector<Vector2D> pos_key = {
        Vector2D(2, 7), Vector2D(2, 9), Vector2D(4, 2), Vector2D(4, 3), Vector2D(4, 6), Vector2D(4, 12),
        Vector2D(6, 3), Vector2D(9, 9), Vector2D(9, 10), Vector2D(10, 2), Vector2D(10, 3), Vector2D(11, 2),
        Vector2D(12, 2), Vector2D(12, 3)
    };
    std::vector<Vector2D> pos_potion = {
        Vector2D(2, 2), Vector2D(2, 3), Vector2D(2, 10), Vector2D(3, 3), Vector2D(8, 9), Vector2D(8, 10),
        Vector2D(10, 9), Vector2D(10, 10)
    };
    std::vector<Vector2D> pos_weapon = {
        Vector2D(3, 2)
    };

    AddArmor(map, pos_armor);
    AddGem(map, pos_gem);
    AddKey(map, pos_key);
    AddPotion(map, pos_potion);
    AddWeapon(map, pos_weapon);

    return map;
}


Scene* CreateLevel2()
{
    Scene *map = new Scene;

    AddWarrior(map, Vector2D(3, 12));

    AddNecessary(map);

    // all tiles
    std::vector<Vector2D> pos_wall = {
        Vector2D(2, 5), Vector2D(2, 8), Vector2D(4, 5), Vector2D(4, 8), Vector2D(6, 4), Vector2D(7, 6),
        Vector2D(7, 8), Vector2D(7, 9), Vector2D(7, 10), Vector2D(8, 4), Vector2D(8, 6), Vector2D(8, 8),
        Vector2D(9, 2), Vector2D(9, 3), Vector2D(9, 4), Vector2D(9, 6), Vector2D(9, 8), Vector2D(10, 4),
        Vector2D(10, 6), Vector2D(12, 4)
    };
    for (int i = 2; i <= 11; i++) pos_wall.emplace_back(Vector2D(i, 11));
    for (int j = 2; j <= 9; j++) pos_wall.emplace_back(Vector2D(5, j));
    for (int j = 6; j <= 10; j++) pos_wall.emplace_back(Vector2D(11, j));
    for (int i = 1; i <= COL_NUM; i++) {
        pos_wall.emplace_back(Vector2D(i, 1));
        pos_wall.emplace_back(Vector2D(i, ROW_NUM));
    }
    for (int j = 2; j < ROW_NUM; j++) {
        pos_wall.emplace_back(Vector2D(1, j));
        pos_wall.emplace_back(Vector2D(COL_NUM, j));
    }
    std::vector<Vector2D> pos_lava;
    std::vector<Vector2D> pos_door = {
        Vector2D(3, 5), Vector2D(3, 8), Vector2D(5, 10), Vector2D(7, 4), Vector2D(7, 7), Vector2D(11, 4),
    };

    AddWall(map, pos_wall);
    AddLava(map, pos_lava);
    AddDoor(map, pos_door);

    map->AddGameObject(new Gate(Vector2D(2, 12), "Level1"));


    // all monsters
    std::vector<Vector2D> pos_slime = {
        Vector2D(5, 12), Vector2D(6, 12), Vector2D(7, 12), Vector2D(9, 7), Vector2D(10, 8)
    };
    std::vector<Vector2D> pos_skeleton = {
        Vector2D(3, 4), Vector2D(3, 7), Vector2D(3, 9), Vector2D(4, 10)
    };
    std::vector<Vector2D> pos_bat = {Vector2D(10, 7)};
    std::vector<Vector2D> pos_cultist = {Vector2D(8, 7), Vector2D(11, 3)};
    std::vector<Vector2D> pos_demon = {Vector2D(7, 3)};

    AddSlime(map, pos_slime);
    AddSkeleton(map, pos_skeleton);
    AddBat(map, pos_bat);
    AddCultist(map, pos_cultist);
    AddDemon(map, pos_demon);


    // all items
    std::vector<Vector2D> pos_armor = {
        Vector2D(2, 6)
    };
    std::vector<Vector2D> pos_gem = {
        Vector2D(4, 9)
    };
    std::vector<Vector2D> pos_key = {
        Vector2D(2, 7), Vector2D(2, 9), Vector2D(4, 2), Vector2D(4, 3), Vector2D(4, 6), Vector2D(4, 12),
        Vector2D(6, 3), Vector2D(9, 9), Vector2D(9, 10), Vector2D(10, 2), Vector2D(10, 3), Vector2D(11, 2),
       Vector2D(12, 2), Vector2D(12, 3)
    };
    std::vector<Vector2D> pos_potion = {
    Vector2D(2, 2), Vector2D(2, 3), Vector2D(2, 10), Vector2D(3, 3), Vector2D(8, 9), Vector2D(8, 10),
    Vector2D(10, 9), Vector2D(10, 10)
    };
    std::vector<Vector2D> pos_weapon = {
        Vector2D(3, 2)
    };

    AddArmor(map, pos_armor);
    AddGem(map, pos_gem);
    AddKey(map, pos_key);
    AddPotion(map, pos_potion);
    AddWeapon(map, pos_weapon);

    return map;
}
