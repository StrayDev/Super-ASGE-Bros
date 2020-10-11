#pragma once
#include "component.h"

class Renderer : public Component
{
public:
    explicit Renderer() = default;
    ~Renderer() override = default;

    void init(GameObject *_gameobject) override;
    virtual void render(ASGE::Renderer* renderer) = 0;

    static std::vector<Renderer*> getRenderComponents() { return render_components; }

protected:
    static std::vector<Renderer*> render_components;

};


