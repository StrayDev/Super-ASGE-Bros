#pragma once
#include <Engine/Renderer.h>
#include "game/components/spriterenderer.h"


class Factory
{
public:
    static ASGE::Renderer* getRenderer() { return renderer; }
    static void setRendererPtr(ASGE::Renderer* ptr) { renderer = ptr; };

protected:
    static ASGE::Renderer* renderer;
};


