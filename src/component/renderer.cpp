#include "component/renderer.h"

Renderer::Renderer(GameObject_Interface *owner):
    Component(owner), enabled(true), visible(true)
{
    transform = owner->GetComponent<Transform>();
}

void Renderer::SetEnabled(bool isEnabled) { enabled = isEnabled; }
bool Renderer::IsEnabled() const { return enabled; }

bool Renderer::IsVisible() const { return visible; }

