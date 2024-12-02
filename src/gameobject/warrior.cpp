#include "gameobject/warrior.h"

Warrior::Warrior(const Vector2D &position)
{
    boxCollider = AddComponent<BoxCollider>();

    rb = AddComponent<RigidBody>();

    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/swordman.svg"));

    stats = AddComponent<Stats>(50, 20, 5);

    transform->position = position;

}

void Warrior::FixedUpdate()
{
    if (Input::GetKeyDown(Qt::Key_A) || Input::GetKeyDown(Qt::Key_Left)) {
        rb->velocity = Vector2D::left;
    }
    else if (Input::GetKeyDown(Qt::Key_D) || Input::GetKeyDown(Qt::Key_Right)) {
        rb->velocity = Vector2D::right;
    }
    else if (Input::GetKeyDown(Qt::Key_W) || Input::GetKeyDown(Qt::Key_Up)) {
        rb->velocity = Vector2D::up;
    }
    else if (Input::GetKeyDown(Qt::Key_S) || Input::GetKeyDown(Qt::Key_Down)) {
        rb->velocity = Vector2D::down;
    }
}

void Warrior::Update()
{

}
