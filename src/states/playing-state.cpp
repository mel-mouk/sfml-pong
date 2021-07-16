#include "playing-state.h"

void PlayingState::init() {
    Field *field = new Field();
    field->setPosition(100, 200);
    _visibleObjectManager.add("field", field);

    Paddle *player1 = new Paddle(field->getTop() + 10, field->getBottom() - 10);
    player1->setPosition(150, 718);
    _visibleObjectManager.add("player1", player1);
}

void PlayingState::handleInput(sf::Event *event) {
    _visibleObjectManager.handleInputAll(event);
}

void PlayingState::update(float timeElapsed) {
    _visibleObjectManager.updateAll(timeElapsed);
}

void PlayingState::draw(sf::RenderWindow *window) {
    _visibleObjectManager.drawAll(window);
}