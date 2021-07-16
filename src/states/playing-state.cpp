#include "playing-state.h"

void PlayingState::init() {
    Field *field = new Field();
    field->setPosition(100, 200);
    _visibleObjectManager.add("field", field);

    Paddle *player1 = new Paddle(field->getTop() + 10, field->getBottom() - 10);
    player1->setPosition(150, 718);
    _visibleObjectManager.add("player1", player1);

    sf::Rect<float> ballConstraint = sf::Rect(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20);
    Ball *ball = new Ball(ballConstraint);
    float centerX = field->getLeft() + field->getBoundingRect().width / 2;
    float centerY = field->getTop() + field->getBoundingRect().height / 2;
    sf::Rect<float> ballRect = ball->getBoundingRect();
    ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
    _visibleObjectManager.add("ball", ball);
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