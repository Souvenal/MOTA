#include "gameobject/warrior.h"

Warrior::Warrior(const Vector2D &position)
{
    boxCollider = AddComponent<BoxCollider>();
    rb = AddComponent<RigidBody>();
    svgRenderer = AddComponent<SvgRenderer>(QString(":/assets/images/swordman.svg"));
    transform->position = position;
}

void Warrior::FixedUpdate()
{
    if (Input::GetKeyDown(Qt::Key_A) ||
        Input::GetKeyDown(Qt::Key_Left)) {
        // qDebug() << "Move Left";
        // transform->Translate(Vector2D::left);
        rb->velocity = Vector2D::left;
    }
    else if (Input::GetKeyDown(Qt::Key_D) ||
        Input::GetKeyDown(Qt::Key_Right)) {
        // qDebug() << "Move Right";
        // transform->Translate(Vector2D::right);
        rb->velocity = Vector2D::right;
    }
    else if (Input::GetKeyDown(Qt::Key_W) ||
        Input::GetKeyDown(Qt::Key_Up)) {
        // qDebug() << "Move Up";
        // transform->Translate(Vector2D::up);
        rb->velocity = Vector2D::up;
    }
    else if (Input::GetKeyDown(Qt::Key_S) ||
        Input::GetKeyDown(Qt::Key_Down)) {
        // qDebug() << "Move Down";
        // transform->Translate(Vector2D::down);
        rb->velocity = Vector2D::down;
    }
}

void Warrior::Update()
{

}
