#ifndef PANG_PLAYING_STATE_H
#define PANG_PLAYING_STATE_H

#include <iostream>
#include "game-state.h"
#include "../objects/entities/field.h"
#include "../objects/entities/paddle.h"
#include "../objects/entities/ball.h"

class PlayingState: public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;
    void endLoopLogic() override;

private:
    int _scorePlayer1 = 0;
    int _scorePlayer2 = 0;
    sf::Font _scoreFont;
    sf::Text _scoreText;
};

#endif //PANG_PLAYING_STATE_H
