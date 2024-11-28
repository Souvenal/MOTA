#include "component/renderer.h"

Renderer::Renderer(GameObject *owner):
    Component(owner), enabled(true), visible(true)
{
    transform = GetComponent<Transform>();
}

void Renderer::SetEnabled(bool isEnabled) { enabled = isEnabled; }
bool Renderer::IsEnabled() const { return enabled; }

bool Renderer::IsVisible() const { return visible; }

