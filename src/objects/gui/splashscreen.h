#ifndef PANG_SPLASHSCREEN_H
#define PANG_SPLASHSCREEN_H

#include "../visible-object.h"

class Splashscreen: public VisibleObject {
public:
    Splashscreen();
    void update(float timeElapsed);
};

#endif //PANG_SPLASHSCREEN_H