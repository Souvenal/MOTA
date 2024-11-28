#include "component/collider.h"

Collider::Collider(GameObject *owner):
    Component(owner)
{
    transform = GetComponent<Transform>();
}


void Collider::OnCollisionEnter(const Collider &other)
{

}

void Collider::OnTriggerEnter(const Collider &other)
{

}
