#ifndef MAP_H
#define MAP_H

#include "module/scene.h"

#define concat(a, b) a##b

#define make_add_func(name) \
void concat(Add, name)(Scene *scene, std::vector<Vector2D> positions) \
{\
        for (const auto &pos : positions) {\
            scene->AddGameObject(new name(pos));\
    }\
}

extern Scene* CreateLevel1();

extern Scene* CreateLevel2();

#endif // MAP_H
