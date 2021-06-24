#ifndef PANG_MENU_STATE_H
#define PANG_MENU_STATE_H

#include "game-state.h"
#include "../pang.h"
#include <iostream>

class MenuState: public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;

private:
    sf::Texture _playTexture;
    sf::Sprite _playSprite;
    sf::Texture _exitTexture;
    sf::Sprite _exitSprite;
};

#endif //PANG_MENU_STATE_H
