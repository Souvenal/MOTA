#include "gameobject/ui/manual.h"

// data
static QStringList headers = {"名称", "血量", "攻击", "防御", "分数", "特性"};
static QStringList monsters[] = {
    {"史莱姆酱", "10", "5", "5", "5", ""},
    {"骷髅士兵", "16", "8", "8", "8", ""},
    {"吸血蝙蝠", "25", "15", "0", "10", "吸血"},
    {"深渊使徒", "50", "30", "15", "25", "精神污染"},
    {"魔王", "100", "25", "15", "100", ""}
};

static int monster_n = 5;


Manual::Manual(const QRectF &rect, const std::string &name, GameObject *parent):
    UIObject(rect, name, parent), isShowing(false)
{
}

void Manual::Update()
{
    if (Input::GetKeyDown(Qt::Key_X)) {
        isShowing = true;
    }
    else if (Input::GetKeyDown(Qt::Key_Z)) {
        isShowing = false;
    }
}

void Manual::Render(QPainter *painter) const
{
    assert(painter);
    if (!isShowing)
        return;

    painter->setPen(Qt::white);
    painter->setBrush(QColor(248, 248, 248, 128));
    painter->drawRoundedRect(rect, 5, 5);

    painter->setFont(QFont("Arial", 12));
    painter->setPen(Qt::black);

    int x = rect.x();      // left
    int y = rect.y() + 10;      // top
    int rowHeight = rect.height() / (monster_n + 1);
    int colWidth = rect.width() / headers.size();

    for (int i = 0; i < headers.size(); ++i)
    {
        painter->drawText(x + i * colWidth, y, headers[i]);
    }

    painter->drawLine(x, y + 5, x + colWidth * headers.size(), y + 5);

    y += rowHeight;
    for (const auto& monster : monsters)
    {
        for (int i = 0; i < monster.size(); ++i)
        {
            painter->drawText(x + i * colWidth, y, monster[i]);
        }
        y += rowHeight;
    }
}
