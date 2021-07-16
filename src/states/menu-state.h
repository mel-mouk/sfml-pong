#ifndef PANG_MENU_STATE_H
#define PANG_MENU_STATE_H

#include <iostream>

#include "game-state.h"
#include "../pang.h"
#include "../objects/gui/play-button.h"
#include "../objects/gui/exit-button.h"

class MenuState: public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;
};

#endif //PANG_MENU_STATE_H
