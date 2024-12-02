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
    explicit GameObject_Impl(const std::string &name, GameObject* parent);
    ~GameObject_Impl();

    void SetActive(bool isActive) override;

    void Start() override;
    void Update() override;
    void FixedUpdate() override;

public:

    Transform *transform;

private:

    Component* GetComponentByType(std::type_index &type) override;
};

#endif // GAMEOBJECT_H
