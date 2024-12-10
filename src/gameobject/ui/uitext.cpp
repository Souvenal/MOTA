#include "gameobject/ui/uitext.h"

UIText::UIText(const QRectF &rect, const QString &text, const QFont &font, const QColor &color,
               const std::string &name, GameObject *parent):
    UIObject(rect, name, parent), text(text), font(font), color(color)
{}

void UIText::SetText(const QString &text) { this->text = text; }

void UIText::SetFont(const QFont &font) { this->font = font; }

void UIText::SetColor(const QColor &color) { this->color = color; }

void UIText::Update() {}

void UIText::Render(QPainter *painter) const
{
    assert(painter);

    painter->setFont(font);
    painter->setPen(color);
    painter->drawText(rect, text, Qt::AlignLeft | Qt::AlignTop);
    // painter->drawRect(rect);
}
