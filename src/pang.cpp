#include "pang.h"

sf::RenderWindow Pang::_window;

void Pang::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(Pang::SCREEN_WIDTH, Pang::SCREEN_HEIGHT, 32), "Pang");

    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
        }
        _window.display();
    }
}
