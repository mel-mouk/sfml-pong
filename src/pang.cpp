#include "pang.h"

sf::RenderWindow Pang::_window;
sf::Clock Pang::_clock;

void Pang::start() {
    if (_window.isOpen()) return;

    _window.create(sf::VideoMode(Pang::SCREEN_WIDTH, Pang::SCREEN_HEIGHT, 32), "Pang");
    _window.setFramerateLimit(60);

    gameLoop();
}

void Pang::gameLoop() {
    while (_window.isOpen()) {
        float timeElapsed = _clock.restart().asSeconds();
        _window.clear(sf::Color(255, 255, 255));

        // Handle input
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { _window.close(); }
            // else handle controls input
        }

        // Update our entities

        // Draw our new entities

        _window.display();
    }
}
