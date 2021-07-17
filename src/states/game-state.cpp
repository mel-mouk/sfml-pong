#include "game-state.h"

GameState::~GameState() { }

VisibleObjectManager* GameState::getObjectManager() {
    return &_visibleObjectManager;
}