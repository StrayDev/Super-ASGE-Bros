#include "startup.h"
#include "menu.h"

void StartUp::init(ASGE::Renderer *renderer)
{
    renderer->setClearColour(ASGE::COLOURS::LIGHTBLUE);
    //renderer->setWindowedMode(ASGE::GameSettings::WindowMode::BORDERLESS_FULLSCREEN);

    initCamera();
    _game->setState(new Menu(_game));
}

void StartUp::initCamera()
{
    auto cam = ASGE::Camera2D{ static_cast<float>(ASGE::SETTINGS.window_width),
                               static_cast<float>(ASGE::SETTINGS.window_height) };
    cam.lookAt(ASGE::Point2D{ static_cast<float>(-ASGE::SETTINGS.window_width) / 2.f,
                              static_cast<float>(-ASGE::SETTINGS.window_height) / 2.f });
    _game->setCamera(cam);
}

