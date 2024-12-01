#include "global.h"
#include "module/scene.h"
#include "gameobject/wall.h"
#include "gameobject/warrior.h"

Scene* CreateMap1()
{
    Scene *map = new Scene;


    for (int i = 1; i <= COL_NUM; i++) {
        map->AddGameObject(new Wall(Vector2D(i, 1)));
        map->AddGameObject(new Wall(Vector2D(i, ROW_NUM)));
    }
    for (int j = 2; j < ROW_NUM; j++) {
        map->AddGameObject(new Wall(Vector2D(1, j)));
        map->AddGameObject(new Wall(Vector2D(COL_NUM, j)));
    }

    map->AddGameObject(new Warrior(Vector2D(7, 3)));

    return map;
}
