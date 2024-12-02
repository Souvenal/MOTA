#include "gameobject/gameobject_impl.h"

void GameObject_Impl::SetActive(bool isActive) {
    if (this->isActive == isActive)
        return;

    this->isActive = isActive;
    for (auto &pair : components) {
        pair.second->SetActive(isActive);
    }
}

bool GameObject_Impl::IsActive() { return this->isActive; }


void GameObject_Impl::Start() {}
void GameObject_Impl::Update() {}
void GameObject_Impl::FixedUpdate() {}

GameObject_Impl::GameObject_Impl()
{
    isActive = true;
    transform = AddComponent<Transform>();
}


GameObject_Impl::~GameObject_Impl()
{
    for (auto &pair : components) {
        pair.second = nullptr;
        delete pair.second;
    }
}

Component* GameObject_Impl::GetComponentByType(std::type_index &type)
{
    auto *component = components[type];
    return dynamic_cast<Component*>(component);
}
