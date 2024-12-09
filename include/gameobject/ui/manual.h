#ifndef MANUAL_H
#define MANUAL_H

#include "gameobject/ui/uiobject.h"

class Manual : public UIObject
{
private:
    bool isShowing;

public:
    Manual(const QRectF &rect, const std::string &name = "Manual", GameObject *parent = nullptr);

    void Update() override;

    void Render(QPainter *painter) const override;
};

#endif // MANUAL_H
