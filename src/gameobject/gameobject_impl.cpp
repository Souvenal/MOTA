#include "gameobject/gameobject_impl.h"

GameObject_Impl::GameObject_Impl(const std::string &name, GameObject *parent):
    GameObject(name, parent)
{
    if (parent) {
        parent->AddChild(name, this);
    }
    transform = AddComponent<Transform>();
}


GameObject_Impl::~GameObject_Impl()
{
    if (parent)
        parent->RemoveChild(name);

    for (auto &pair : children) {
        delete pair.second;
    }

    for (auto &pair : components) {
        delete pair.second;
    }
}

void GameObject_Impl::SetActive(bool isActive) {
    if (this->isActive == isActive)
        return;

    this->isActive = isActive;


    for (auto &pair : children) {
        GameObject* child = pair.second;
        child->SetActive(isActive);
    }

    for (auto &pair : components) {
        Component *component = pair.second;
        if (component)
            pair.second->SetActive(isActive);
    }
}

void GameObject_Impl::SetTag(const std::string &tag) { this->tag = tag; }
bool GameObject_Impl::CompareTag(const std::string &tag) const { return this->tag == tag; }

void GameObject_Impl::Start() {}
void GameObject_Impl::Update()
{
    // update children gameobjects
    for (auto &pair: children) {
        GameObject *child = pair.second;
        child->Update();
    }
}
void GameObject_Impl::FixedUpdate()
{
    // fixedupdate children gameobjects
    for (auto &pair: children) {
        GameObject *child = pair.second;
        child->FixedUpdate();
    }
}

void GameObject_Impl::OnCollisionEnter(Collider *other)
{
    Collider *collider = GetComponent<Collider>();
    if (!collider || collider->isTrigger)
        return;
}

void GameObject_Impl::OnTriggerEnter(Collider *other)
{
    Collider *collider = GetComponent<Collider>();
    if (!collider || !collider->isTrigger)
        return;
}


Component* GameObject_Impl::GetComponentByType(std::type_index &type)
{
    auto *component = components[type];
    return dynamic_cast<Component*>(component);
}
