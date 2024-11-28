#ifndef GAMEOBJECT_INTERFACE_HPP
#define GAMEOBJECT_INTERFACE_HPP

#include <typeindex>
#include <unordered_map>

#include "component/componentfactory.hpp"

class Component;

class GameObject_Interface
{
protected:
    std::unordered_map<std::type_index, Component *> components;

public:
    template<typename T, typename... Args>
    T* AddComponent(Args&&... args);


    virtual Component* GetComponentByType(std::type_index &type) = 0;

    template<typename T>
    T* GetComponent();
};



template<typename T, typename... Args>
T* GameObject_Interface::AddComponent(Args&&... args)
{
    T* component = ComponentFactory::GetComponentFactory()
        .Create<T>(this, std::forward<Args>(args)...);
    components[std::type_index(typeid(T))] = component;
    return component;
}


template<typename T>
T* GameObject_Interface::GetComponent()
{
    std::type_index type = std::type_index(typeid(T));
    Component *component = GetComponentByType(type);
    return dynamic_cast<T*>(component);
}


#endif // GAMEOBJECT_INTERFACE_HPP
