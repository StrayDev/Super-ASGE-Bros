#include "textrenderer.h"

#include <Engine/Logger.hpp>

int TextRenderer::font_index;

void TextRenderer::init(GameObject *_gameobject)
{
    RenderComponent::init(_gameobject);
}

void TextRenderer::render(ASGE::Renderer *renderer)
{
    if(!text) return;
    renderer->renderText(*text);
}

void TextRenderer::loadFont(ASGE::Renderer* renderer)
{
    auto file  = ASGE::FILEIO::File();
    Logging::log("\n");

    if (file.open("data/fonts/prstart.ttf", ASGE::FILEIO::File::IOMode::READ))
    {
        auto buffer = file.read();

        if (buffer.length)
        {
            font_index = renderer->loadFontFromMem( "Press Start", buffer.as_unsigned_char(),
                                                    static_cast<unsigned int>(buffer.length), 32);
        }
        file.close();
    }
}

void TextRenderer::createText(ASGE::Renderer *renderer, std::string string, float scale)
{
    text = new ASGE::Text(renderer->getFont(font_index), string);
    text->setScale(scale);
}



