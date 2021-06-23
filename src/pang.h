#ifndef PANG_PANG_H
#define PANG_PANG_H

#include <SFML/Graphics.hpp>

class Pang {
public:
    const static int SCREEN_WIDTH = 2048;
    const static int SCREEN_HEIGHT = 1536;
    static void start();

private:
    static sf::RenderWindow _window;
};

#endif //PANG_PANG_H
