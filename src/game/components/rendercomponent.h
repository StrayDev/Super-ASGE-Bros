#pragma once
#include "component.h"

class RenderComponent : public Component
{
public:
    explicit RenderComponent() = default;
    virtual ~RenderComponent();

    void init(GameObject *_gameobject) override;
    virtual void render(ASGE::Renderer* renderer) = 0;

    static std::vector<RenderComponent*> getRenderComponents() { return render_components; }

protected:
    static std::vector<RenderComponent*> render_components;

};


