#include "splashscreen-state.h"

void SplashscreenState::init() {
    Splashscreen *splashscreen = new Splashscreen();
    _visibleObjectManager.add("splashscreen", splashscreen);
}

void SplashscreenState::handleInput(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed) {
        Pang::setState(Pang::Menu);
    }
    _visibleObjectManager.handleInputAll(event);
}

void SplashscreenState::update(float timeElapsed) {
    _visibleObjectManager.updateAll(timeElapsed);
}

void SplashscreenState::draw(sf::RenderWindow *window) {
    _visibleObjectManager.drawAll(window);
}
