#include "playing-state.h"

void PlayingState::init() {
    if (!_player1Texture.loadFromFile("../assets/paddle.png")) {
        std::cout << "Error while loading paddle assets" << std::endl;
        return;
    }

    _player1Sprite.setTexture(_player1Texture);
    _player1Sprite.setPosition(150, 718);
}

void PlayingState::handleInput(sf::Event *event) { }

void PlayingState::update(float timeElapsed) { }

void PlayingState::draw(sf::RenderWindow *window) {
    window->draw(_player1Sprite);
}