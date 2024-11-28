#ifndef RENDERER_H
#define RENDERER_H

#include <QPainter>

#include "component/transform.h"
#include "cordinate.h"

class Renderer : public Component
{
    BAN_DEFAULT_CONSTURCTOR(Renderer)

protected:
    bool enabled;
    bool visible;


    Transform *transform;

public:
    Renderer(GameObject_Interface *owner);

    void SetEnabled(bool isEnabled);
    bool IsEnabled() const;

    virtual bool IsVisible() const;

    virtual void Render(QPainter *painter) const = 0;

    virtual ~Renderer() = default;
};

#endif // RENDERER_H
