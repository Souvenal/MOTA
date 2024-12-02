#ifndef UIOBJECT_H
#define UIOBJECT_H

#include <QPainter>

#include "gameobject/gameobject_impl.h"

class UIObject : public GameObject_Impl
{
    BAN_DEFAULT_CONSTURCTOR(UIObject)

public:

    explicit UIObject(const QRectF &rect, const std::string &name, GameObject *parent = nullptr);

    virtual void Update() = 0;
    virtual void Render(QPainter *painter) const = 0;

protected:
    QRectF rect; // position
};

#endif // UIOBJECT_H
