#include "play-button.h"

PlayButton::PlayButton() : VisibleObject("../assets/play-btn.png") { }

void PlayButton::handleInput(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        int x = event->mouseButton.x;
        int y = event->mouseButton.y;
        if (getBoundingRect().contains(x, y)) {
            Pang::setState(Pang::Playing);
        }
    }
}

void PlayButton::update(float timeElapsed) { }