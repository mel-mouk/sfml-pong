#include "paddle.h"

Paddle::Paddle(float constraintTop, float constraintBottom) : VisibleObject("../assets/paddle.png") {
    // So we don't recalculate fieldBound on each turn as it never changes
    _constraintTop = constraintTop;
    _constraintBottom = constraintBottom;
}

void Paddle::handleInput(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Up) {
            _direction = DIRECTION_UP;
        } else if (event->key.code == sf::Keyboard::Down) {
            _direction = DIRECTION_DOWN;
        }
    } else if (event->type == sf::Event::KeyReleased) {
        _direction = DIRECTION_NONE;
    }
}

void Paddle::update(float timeElapsed) {
    float velocity = 0.0f;

    if (_direction == DIRECTION_UP) {
        velocity = _speed * -1;
    } else if (_direction == DIRECTION_DOWN) {
        velocity = _speed;
    }
    
    move(0, velocity * timeElapsed);

    sf::Vector2 pos = getPosition();
    if (pos.y < _constraintTop) {
        setPosition(pos.x, _constraintTop);
    } else if (pos.y + getBoundingRect().height > _constraintBottom) {
        setPosition(pos.x, _constraintBottom - getBoundingRect().height);
    }
}