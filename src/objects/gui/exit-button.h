#ifndef PANG_EXIT_BUTTON_H
#define PANG_EXIT_BUTTON_H

#include "../../pang.h"
#include "../visible-object.h"

class ExitButton: public VisibleObject {
public:
    ExitButton();
    void handleInput(sf::Event *event);
    void update(float timeElapsed);
};

#endif //PANG_EXIT_BUTTON_H