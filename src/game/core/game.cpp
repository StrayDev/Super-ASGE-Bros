#include "game/gamestates/startup.h"

///Constructor.
ASGEGame::ASGEGame(ASGE::GameSettings settings) : OGLGame(settings)
{
    inputs->use_threads = false;
    //toggleFPS();

    _input = new Input();
    setState(new StartUp(this));
}

///Destructor
ASGEGame::~ASGEGame()
{
    delete _input;
    delete _gameState; // do i need this vs should i have it
    inputs->unregisterCallback(static_cast<unsigned int>(key_callback_id));
    inputs->unregisterCallback(static_cast<unsigned int>(mouse_callback_id));
}

///Init
bool ASGEGame::init()
{
    key_callback_id = inputs->addCallbackFnc(ASGE::E_KEY, &ASGEGame::keyHandler, this);
    return true;
}

///Key input
void ASGEGame::keyHandler(const ASGE::SharedEventData& data)
{
    const auto* key = dynamic_cast<const ASGE::KeyEvent*>(data.get());
    _input->get(key, this);
}

///Update
void ASGEGame::update(const ASGE::GameTime& game_time)
{
    auto delta_time = game_time.delta.count() / 1000.0;

    if (inputs->getGamePad(0).is_connected)
    {
        _camera.translateX(inputs->getGamePad(0).axis[0] * -100);
        _camera.translateY(inputs->getGamePad(0).axis[1] * -100);
    }

    _camera.update(game_time);
    _gameState->update(delta_time);
}

///rendercomponent
void ASGEGame::render()
{
    renderer->setProjectionMatrix(_camera.getView());
    _gameState->render(renderer.get());
}

void ASGEGame::setState(GameState *state)
{
    delete _gameState;
    _gameState = state;
    _gameState->init(renderer.get());
}


