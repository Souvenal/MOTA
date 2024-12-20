#include "component/svgrenderer.h"

SvgRenderer::SvgRenderer(GameObject *owner, const QString &svg):
    Renderer(owner), svg(svg)
{
    renderer = new QSvgRenderer;
    renderer->load(svg);
}

SvgRenderer::~SvgRenderer()
{
    delete renderer;
}


// default render
void SvgRenderer::Render(QPainter *painter) const
{
    if (!IsActive() || !painter)
        return;

    renderer->render(
        painter,
        Cordinate::GetRect(transform->position)
    );
}
