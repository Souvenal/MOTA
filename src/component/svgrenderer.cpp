#include "component/svgrenderer.h"

SvgRenderer::SvgRenderer(GameObject_Interface *owner, const QString &svg):
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
    renderer->render(
        painter,
        Cordinate::GetRect(transform->position)
    );
}
