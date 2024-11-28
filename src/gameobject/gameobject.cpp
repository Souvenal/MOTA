#include "gameobject/gameobject.h"

// template<typename T, typename... Args>
// T* GameObject::AddComponent(Args&&... args)
// {
//     std::type_index type = std::type_index(typeid(T));
//     T* component = new T(std::forward<Args>(args)...);
//     components[type] = component;
//     return component;
// }


Component* GameObject::GetComponentByType(std::type_index &type)
{
    auto *component = components[type];
    return dynamic_cast<Component*>(component);
}

GameObject::GameObject()
{
    transform = AddComponent<Transform>();
}

GameObject::~GameObject()
{
    for (auto &pair : components)
        delete pair.second;
}
