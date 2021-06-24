#ifndef PANG_PLAYING_STATE_H
#define PANG_PLAYING_STATE_H

#include "game-state.h"

class PlayingState: public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;
};

#endif //PANG_PLAYING_STATE_H
