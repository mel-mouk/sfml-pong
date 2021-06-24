#include "paddle.h"

void Paddle::init() {
    if (!_texture.loadFromFile("../assets/paddle.png")) {
        std::cout << "Error while loading paddle assets" << std::endl;
        return;
    }

    _sprite.setTexture(_texture);
}

void Paddle::draw(sf::RenderWindow *window) {
    window->draw(_sprite);
}

void Paddle::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

