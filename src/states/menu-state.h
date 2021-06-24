#ifndef PANG_MENU_STATE_H
#define PANG_MENU_STATE_H

#include "game-state.h"

class MenuState: public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;
};

#endif //PANG_MENU_STATE_H
