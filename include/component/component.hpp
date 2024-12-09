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


public:
    Component(GameObject *owner):
        owner(owner)
    {}

    virtual ~Component() = default;

    template <typename T>
    T* GetComponent()
    {
        return owner->GetComponent<T>();
    }

    void SetActive(bool isActive) { this->isActive = isActive; }
    bool IsActive() const { return this->isActive; }

    bool CompareTag(const std::string &tag) const { return owner->CompareTag(tag); }

    GameObject* GetOwner() const { return owner; }
protected:
    GameObject *owner;

    bool isActive = true;
};


#endif // COMPONENT_H
