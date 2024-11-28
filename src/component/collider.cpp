#include "component/collider.h"

Collider::Collider(GameObject_Interface *owner):
    Component(owner)
{
    transform = owner->GetComponent<Transform>();
}

bool Collider::IsColliding(const Collider &other) const
{

}

void Collider::OnCollisionEnter(const Collider &other)
{

}

void Collider::OnTriggerEnter(const Collider &other)
{

}
