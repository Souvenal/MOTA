#include "component/canvasrenderer.h"

CanvasRenderer::CanvasRenderer(GameObject *owner):
    Renderer(owner)
{
    layout = new QVBoxLayout;
}
