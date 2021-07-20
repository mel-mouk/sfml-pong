#ifndef PANG_BALL_H
#define PANG_BALL_H

#include <cmath>

#include "../visible-object.h"
#include "paddle.h"

class Ball : public VisibleObject {
public:
    bool isOut;

    Ball(sf::Rect<float> constraints);
    void update(float timeElapsed);
    void collideWith(VisibleObject *target);

private:
    int _angle;
    float _speed;
    float _maxSpeed = 1800.0f;
    float _timeElapsed;
    sf::Rect<float> _constraints;
};

#endif //PANG_BALL_H