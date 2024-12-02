#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utility>
#include <typeindex>
#include <unordered_map>

#include "component/transform.h"
#include "gameobject/gameobject.hpp"

class GameObject_Impl : public GameObject
{
public:

    void SetActive(bool isActive) override;
    bool IsActive() override;

    void Start() override;
    void Update() override;
    void FixedUpdate() override;


    GameObject_Impl();
    ~GameObject_Impl();

public:

    Transform *transform;

private:

    Component* GetComponentByType(std::type_index &type) override;
};

#endif // GAMEOBJECT_H
