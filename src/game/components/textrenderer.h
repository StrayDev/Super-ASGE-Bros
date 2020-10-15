#pragma once
#include <Engine/FileIO.h>
#include "rendercomponent.h"

class TextRenderer : public RenderComponent
{
public:
    TextRenderer() = default;
    ~TextRenderer() override = default;

    void init(GameObject *_gameobject) override;
    void render(ASGE::Renderer *renderer) override;

    void createText(ASGE::Renderer* renderer, std::string string, float scale);

    static void loadFont(ASGE::Renderer* renderer);

private:
    ASGE::Text* text = nullptr;

    static int font_index;
};


