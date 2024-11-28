#ifndef COMPONENT_H
#define COMPONENT_H

#include <typeindex>
#include <unordered_map>

#include "gameobject/gameobject.hpp"

#define BAN_DEFAULT_CONSTURCTOR(Component) \
    Component() = delete;\
    Component(const Component&) = delete;\
    Component(Component&&) = delete;\
    Component& operator=(const Component&) = delete;\
    Component& operator=(Component&&) = delete;

class Component
{
    BAN_DEFAULT_CONSTURCTOR(Component)

protected:
    GameObject *owner;

    template <typename T>
    T* GetComponent()
    {
        return owner->GetComponent<T>();
    }

public:

    Component(GameObject *owner):
        owner(owner)
    {}

    virtual ~Component() = default;
};


#endif // COMPONENT_H