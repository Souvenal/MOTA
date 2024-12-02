#ifndef TILE_H
#define TILE_H

#include "component/components.h"
#include "gameobject/gameobject_impl.h"

class Tile : public GameObject_Impl
{
protected:
    SvgRenderer *renderer;

public:
    Tile();
};

#endif // TILE_H
