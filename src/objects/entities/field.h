#ifndef PANG_FIELD_H
#define PANG_FIELD_H

#include "../visible-object.h"

class Field: public VisibleObject {
public:
    Field();
    void update(float timeElapsed);
};

#endif //PANG_FIELD_H