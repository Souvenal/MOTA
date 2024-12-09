#include "gameobject/ui/manual.h"

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
    if (!isShowing)
        return;


}
