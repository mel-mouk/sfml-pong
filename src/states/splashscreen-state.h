#ifndef PANG_SPLASHSCREEN_STATE_H
#define PANG_SPLASHSCREEN_STATE_H

#include "../pang.h"
#include "game-state.h"
#include "../objects/gui/splashscreen.h"
#include <iostream>

class SplashscreenState : public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;
};

#endif //PANG_SPLASHSCREEN_STATE_H
