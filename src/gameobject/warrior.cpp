#include "gameobject/warrior.h"

Warrior::Warrior(const Vector2D &position, const std::string &name, GameObject *parent)
    :Character(name, parent)
{
    SetTag("Player");

    renderer = AddComponent<SvgRenderer>(QStringLiteral(":/assets/images/swordman.svg"));

    currentHealth = maxHealth = 50;
    attack = 20;
    defence = 5;
    currentCoins = 0;
    currentKeys = 0;

    transform->position = position;
}

void Warrior::AddCoins(int coins) { currentCoins += coins; }

void Warrior::AddKeys(int keys) { currentKeys += keys; }

void Warrior::Attack(Character *other)
{
    if (!other->CompareTag("Monster"))
        return;

    other->TakeDamage(attack);
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
        text->SetText(QStringLiteral("Attack: ") + QString::number(attack));
    }
    if (children["DefenceText"]) {
        auto text = dynamic_cast<UIText*>(children["DefenceText"]);
        text->SetText(QStringLiteral("Defence: ") + QString::number(defence));
    }
    if (children["HealthText"]) {
        auto text = dynamic_cast<UIText*>(children["HealthText"]);
        text->SetText(QStringLiteral("Health: ") + QString::number(currentHealth)
                      + QStringLiteral("/")+ QString::number(maxHealth));
    }
    if (children["CoinsText"]) {
        auto text = dynamic_cast<UIText*>(children["CoinsText"]);
        text->SetText(QStringLiteral("Coins: ") + QString::number(currentCoins));
    }
    GameObject_Impl::Update();
}

void Warrior::OnCollisionEnter(Collider *other)
{
    if (!other->CompareTag("Monster"))
        return;

    Character *monster = dynamic_cast<Character*>(other->GetOwner());
    assert(monster);
    qDebug() << "attack!";
    BattleManager::GetBattleManager()->StartBattle(this, monster);
}
