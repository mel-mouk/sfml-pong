#ifndef PANG_PADDLE_H
#define PANG_PADDLE_H

#include "../../pang.h"
#include "../visible-object.h"
#include "ball.h"

class Paddle: public VisibleObject {
public:
    Paddle(float constraintTop, float constraintBottom);
    void handleInput(sf::Event *event);
    void update(float timeElapsed);
    void runAI();

    bool isAI;

private:
    enum Direction { DIRECTION_NONE, DIRECTION_UP, DIRECTION_DOWN };

    Direction _direction = DIRECTION_NONE;
    float _speed = 800.0f;
    float _constraintTop;
    float _constraintBottom;
};

#endif //PANG_PADDLE_H