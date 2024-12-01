#include "gameobject/gameobject_impl.h"


Component* GameObject_Impl::GetComponentByType(std::type_index &type)
{
    auto *component = components[type];
    return dynamic_cast<Component*>(component);
}

GameObject_Impl::GameObject_Impl()
{
    transform = AddComponent<Transform>();
}

void GameObject_Impl::Start() {}
void GameObject_Impl::Update() {}
void GameObject_Impl::FixedUpdate() {}


GameObject_Impl::~GameObject_Impl()
{
    for (auto &pair : components) {
        pair.second = nullptr;
        delete pair.second;
    }
}
