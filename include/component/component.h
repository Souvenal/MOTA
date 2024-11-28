#ifndef COMPONENT_H
#define COMPONENT_H

#include <typeindex>
#include <unordered_map>

#include "gameobject/gameobject_interface.hpp"

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
    GameObject_Interface *owner;
public:

    Component(GameObject_Interface *owner);

    virtual ~Component() = default;
};


#endif // COMPONENT_H
