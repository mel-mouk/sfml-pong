#ifndef PANG_PADDLE_H
#define PANG_PADDLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle {
public:
    void init();
    void draw(sf::RenderWindow *window);

    void setPosition(float x, float y);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
};


#endif //PANG_PADDLE_H
