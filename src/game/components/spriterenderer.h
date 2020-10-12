#pragma once
#include "RenderComponent.h"

class SpriteRenderer : public RenderComponent
{
public:
    SpriteRenderer() = default;
    ~SpriteRenderer() override = default;

    void init(GameObject *_gameobject) override;
    void render(ASGE::Renderer *renderer) override;

    void createSprite(ASGE::Renderer* renderer, std::string file_path);
    void setSpriteSize(Vector2 size) { sprite->width(size.x()); sprite->height(size.y()); }
    void setSpritePosition(Vector2 pos) { sprite->xPos(pos.x()); sprite->yPos(pos.y()); }

    void debug_SetSpriteScale(float i) { sprite->scale(i); } ///change to set sprite dimentions


private:
    ASGE::Sprite* sprite = nullptr;
};


