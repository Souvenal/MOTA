#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <QSvgRenderer>

#include "component/renderer.h"
#include "component/transform.h"

class SvgRenderer : public Renderer
{
    BAN_DEFAULT_CONSTURCTOR(SvgRenderer)

private:
    QString svg; // path of svg
    QSvgRenderer* renderer;

public:
    SvgRenderer(GameObject_Interface *owner, const QString &svg);
    ~SvgRenderer();

    void Render(QPainter *painter) const override;
};

#endif // SPRITERENDERER_H
