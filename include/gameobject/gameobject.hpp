#ifndef GAMEOBJECT_INTERFACE_HPP
#define GAMEOBJECT_INTERFACE_HPP

#include <typeindex>
#include <unordered_map>

#include "component/componentfactory.hpp"

class Component;

// interface class
class GameObject
{
public:
    explicit GameObject(const std::string &name, GameObject *parent = nullptr):
        name(name), parent(parent), isActive(true)
    {}
    virtual ~GameObject() {}

    virtual void AddChild(const std::string &name, GameObject* child)
    {
        children[name] = child;
    }
    virtual void RemoveChild(const std::string &name)
    {
        children.erase(name);
    }

    template<typename T, typename... Args>
    T* AddComponent(Args&&... args); // deal with components

    template<typename T>
    T* GetComponent(); // deal with components

    virtual void SetActive(bool isActive) = 0; // deal with gameobjects
    virtual bool IsActive() const { return isActive; }

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void FixedUpdate() = 0;

public:
    std::string name;

    GameObject* parent;

protected:
    std::unordered_map<std::string, GameObject *> children;

    std::unordered_map<std::type_index, Component *> components;

    virtual Component* GetComponentByType(std::type_index &type) = 0;

    bool isActive;
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
