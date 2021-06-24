#ifndef PANG_PANG_H
#define PANG_PANG_H

#include <SFML/Graphics.hpp>
#include "states/game-state.h"
#include "states/splashscreen-state.h"
#include "states/menu-state.h"
#include "states/playing-state.h"

class Pang {
public:
    const static int SCREEN_WIDTH = 2048;
    const static int SCREEN_HEIGHT = 1536;
    static void start();
    static void gameLoop();

    enum State { Uninitialized, Splashscreen, Menu, Playing, Exiting };
    static void setState(State s);

private:
    static State _state;
    static std::map<State, GameState*> _stateInstances;
    static sf::RenderWindow _window;
    static sf::Clock _clock;
};

#endif //PANG_PANG_H
