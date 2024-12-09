#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utility>
#include <typeindex>
#include <unordered_map>

#include "component/components.h"
#include "gameobject/gameobject.hpp"

class GameObject_Impl : public GameObject
{
public:
    explicit GameObject_Impl(const std::string &name, GameObject* parent);
    ~GameObject_Impl();

    void SetActive(bool isActive) override;
    void SetTag(const std::string &tag) override;
    bool CompareTag(const std::string &tag) const override;

    void Start() override;
    void Update() override;
    void FixedUpdate() override;

    void OnCollisionEnter(Collider *other) override;
    void OnTriggerEnter(Collider *other) override;

public:

    Transform *transform;

private:

    Component* GetComponentByType(std::type_index &type) override;
};

#endif // GAMEOBJECT_H
