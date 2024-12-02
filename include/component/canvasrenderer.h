#ifndef CANVASRENDERER_H
#define CANVASRENDERER_H

#include <QVBoxLayout>
#include <QLabel>

#include "component/renderer.h"

class CanvasRenderer : public Renderer
{
public:

    CanvasRenderer(GameObject *owner);

private:

    QVBoxLayout *layout;

    std::unordered_map<std::string, QLabel*> labels;
};

#endif // CANVASRENDERER_H
