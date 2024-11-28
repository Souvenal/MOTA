#include "gameobject/gameobject_impl.h"

// template<typename T, typename... Args>
// T* (GameObject_Impl)::AddComponent(Args&&... args)
// {
//     std::type_index type = std::type_index(typeid(T));
//     T* component = new T(std::forward<Args>(args)...);
//     components[type] = component;
//     return component;
// }


Component* GameObject_Impl::GetComponentByType(std::type_index &type)
{
    auto *component = components[type];
    return dynamic_cast<Component*>(component);
}

GameObject_Impl::GameObject_Impl()
{
    transform = AddComponent<Transform>();
}

GameObject_Impl::~GameObject_Impl()
{
    for (auto &pair : components)
        delete pair.second;
}
