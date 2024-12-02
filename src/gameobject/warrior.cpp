#include "gameobject/warrior.h"

Warrior::Warrior(const Vector2D &position, const std::string &name, GameObject *parent)
    :GameObject_Impl(name, parent)
{
    boxCollider = AddComponent<BoxCollider>();

    rb = AddComponent<RigidBody>();

    svgRenderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/swordman.svg"));

    stats = AddComponent<WarriorStats>(50, 20, 5, 0);

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

    GameObject_Impl::FixedUpdate();
}

void Warrior::Update()
{
    if (children["AttackText"]) {
        auto text = dynamic_cast<UIText*>(children["AttackText"]);
        text->SetText(QStringLiteral("Attack: ") + QString::number(stats->attack));
    }
    if (children["DefenceText"]) {
        auto text = dynamic_cast<UIText*>(children["DefenceText"]);
        text->SetText(QStringLiteral("Defence: ") + QString::number(stats->defence));
    }
    if (children["HealthText"]) {
        auto text = dynamic_cast<UIText*>(children["HealthText"]);
        text->SetText(QStringLiteral("Health: ") + QString::number(stats->currentHealth));
    }
    if (children["CoinsText"]) {
        auto text = dynamic_cast<UIText*>(children["CoinsText"]);
        text->SetText(QStringLiteral("Coins: ") + QString::number(stats->currentCoins));
    }
    GameObject_Impl::Update();
}
