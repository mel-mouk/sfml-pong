#include "menu-state.h"

void MenuState::init() {
    PlayButton *playButton = new PlayButton();
    playButton->setPosition(422, 490);
    _visibleObjectManager.add("playButton", playButton);

    ExitButton *exitButton = new ExitButton();
    exitButton->setPosition(422, 868);
    _visibleObjectManager.add("exitButton", exitButton);
}

void MenuState::handleInput(sf::Event *event) {
    _visibleObjectManager.handleInputAll(event);
}

void MenuState::update(float timeElapsed) {
    _visibleObjectManager.updateAll(timeElapsed);
}

void MenuState::draw(sf::RenderWindow *window) {
    _visibleObjectManager.drawAll(window);
}