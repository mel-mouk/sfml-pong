#ifndef PANG_BALL_H
#define PANG_BALL_H

#include <cmath>

#include "../visible-object.h"

class Ball : public VisibleObject {
public:
    Ball(sf::Rect<float> constraints);
    void update(float timeElapsed);

private:
    int _angle;
    float _speed;
    sf::Rect<float> _constraints;
};

#endif //PANG_BALL_H