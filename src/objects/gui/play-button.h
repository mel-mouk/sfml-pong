#ifndef PANG_PLAY_BUTTON_H
#define PANG_PLAY_BUTTON_H

#include "../../pang.h"
#include "../visible-object.h"

class PlayButton: public VisibleObject {
public:
    PlayButton();
    void handleInput(sf::Event *event);
    void update(float timeElapsed);
};

#endif //PANG_PLAY_BUTTON_H