#include "playing-state.h"

void PlayingState::init() {
    _player.init();
    _player.setPosition(150, 718);
}

void PlayingState::handleInput(sf::Event *event) { }

void PlayingState::update(float timeElapsed) { }

void PlayingState::draw(sf::RenderWindow *window) {
    _player.draw(window);
}