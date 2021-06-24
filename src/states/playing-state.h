#ifndef PANG_PLAYING_STATE_H
#define PANG_PLAYING_STATE_H

#include <iostream>
#include "game-state.h"

class PlayingState: public GameState {
public:
    void init() override;
    void handleInput(sf::Event *event) override;
    void update(float timeElapsed) override;
    void draw(sf::RenderWindow *window) override;

private:
    // Field
    sf::Texture _fieldTexture;
    sf::Sprite _fieldSprite;
    // Player
    sf::Texture _player1Texture;
    sf::Sprite _player1Sprite;
    float _playerSpeed = 800.0f;
    enum Direction { DIRECTION_NONE, DIRECTION_UP, DIRECTION_DOWN };
    Direction _playerDirection = DIRECTION_NONE;
};

#endif //PANG_PLAYING_STATE_H
