#pragma once
#include "Renderer.h"

class SpriteRenderer : public Renderer
{
public:
    explicit SpriteRenderer(GameObject* _gameobject);
    ~SpriteRenderer() override = default;

    void init(GameObject *_gameobject) override;
    void render(ASGE::Renderer *renderer) override;

    void createSprite(ASGE::Renderer* renderer, std::string file_path);
    void debug_SetSPriteScale(int i) { sprite->scale(i); }

private:
    ASGE::Sprite* sprite = nullptr;
};


