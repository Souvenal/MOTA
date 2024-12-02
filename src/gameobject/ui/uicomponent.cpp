#include "gameobject/ui/uiobject.h"

UIObject::UIObject(const QRectF &rect, const std::string &name, GameObject *parent):
    GameObject_Impl(name, parent), rect(rect)
{}
