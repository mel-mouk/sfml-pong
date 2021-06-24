#include "splashscreen-state.h"

void SplashscreenState::init() {
    if (!_texture.loadFromFile("../assets/splashscreen.png")) {
        std::cout << "Error while loading Splashscreen assets " << std::endl;
        return;
    }
    _sprite.setTexture(_texture);
}

void SplashscreenState::handleInput(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed) {
        Pang::setState(Pang::Menu);
    }
}

void SplashscreenState::update(float timeElapsed) { }

void SplashscreenState::draw(sf::RenderWindow *window) {
    window->draw(_sprite);
}
