#ifndef UITEXT_H
#define UITEXT_H

#include "gameobject/ui/uiobject.h"

class UIText : public UIObject
{
    BAN_DEFAULT_CONSTURCTOR(UIText)

public:
    explicit UIText(const QRectF &rect, const QString &text, const QFont &font, const QColor &color, const std::string &name, GameObject *parent = nullptr);

    void SetText(const QString &text);
    void SetFont(const QFont &font);
    void SetColor(const QColor &color);

    void Update() override;
    void Render(QPainter *painter) const override;

private:
    QString text;
    QFont font;
    QColor color;
};

#endif // UITEXT_H
