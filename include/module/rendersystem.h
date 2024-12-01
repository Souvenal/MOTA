#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "component/svgrenderer.h"

class RenderSystem
{
public:
    RenderSystem();

    void Render(std::vector<Renderer*> renderers, QPainter *painter);
};

#endif // RENDERSYSTEM_H
