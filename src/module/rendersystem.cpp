#include "module/rendersystem.h"

RenderSystem::RenderSystem() {}

void RenderSystem::Render(std::vector<Renderer *> renderers, QPainter *painter)
{
    for (auto &renderer : renderers) {
        if (renderer->IsActive())
            renderer->Render(painter);
    }
}
