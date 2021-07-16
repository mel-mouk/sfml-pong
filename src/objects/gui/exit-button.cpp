#include "exit-button.h"

ExitButton::ExitButton() : VisibleObject("../assets/exit-btn.png") { }

void ExitButton::handleInput(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        int x = event->mouseButton.x;
        int y = event->mouseButton.y;
        if (getBoundingRect().contains(x, y)) {
            Pang::setState(Pang::Playing);
        }
    }
}

void ExitButton::update(float timeElapsed) { }