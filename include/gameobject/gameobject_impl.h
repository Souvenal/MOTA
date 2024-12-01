#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utility>
#include <typeindex>
#include <unordered_map>

#include "component/transform.h"
#include "gameobject/gameobject.hpp"

class GameObject_Impl : public GameObject
{
private:
    Component* GetComponentByType(std::type_index &type) override;

public:
    GameObject_Impl();

    void Start() override;
    void Update() override;
    void FixedUpdate() override;

    ~GameObject_Impl();

public:
    Transform *transform;

};

#endif // GAMEOBJECT_H
