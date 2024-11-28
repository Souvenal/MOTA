#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utility>
#include <typeindex>
#include <unordered_map>

#include "input.h"
#include "component/transform.h"
#include "gameobject_interface.hpp"

class GameObject : public GameObject_Interface
{
private:
    Component* GetComponentByType(std::type_index &type) override;

public:
    GameObject();
    virtual ~GameObject();

public:
    Transform *transform;

    virtual void Start() = 0;
    virtual void Update() = 0;

};

#endif // GAMEOBJECT_H
