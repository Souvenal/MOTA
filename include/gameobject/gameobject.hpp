#ifndef GAMEOBJECT_INTERFACE_HPP
#define GAMEOBJECT_INTERFACE_HPP

#include <typeindex>
#include <unordered_map>

#include "component/componentfactory.hpp"

class Component;

// interface class
class GameObject
{
protected:
    std::unordered_map<std::type_index, Component *> components;

    virtual Component* GetComponentByType(std::type_index &type) = 0;

    bool isActive;

public:
    template<typename T, typename... Args>
    T* AddComponent(Args&&... args);

    template<typename T>
    T* GetComponent();

    virtual void SetActive(bool isActive) = 0;
    virtual bool IsActive() = 0;

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void FixedUpdate() = 0;

    GameObject() = default;
    virtual ~GameObject() {}
};



template<typename T, typename... Args>
T* GameObject::AddComponent(Args&&... args)
{
    T* component = ComponentFactory::GetComponentFactory()
        .Create<T>(this, std::forward<Args>(args)...);
    components[std::type_index(typeid(T))] = component;
    return component;
}


template<typename T>
T* GameObject::GetComponent()
{
    std::type_index type = std::type_index(typeid(T));
    Component *component = GetComponentByType(type);
    return dynamic_cast<T*>(component);
}


#endif // GAMEOBJECT_INTERFACE_HPP
