#include "visible-object-manager.h"

VisibleObjectManager::~VisibleObjectManager() {
    auto itr = _objects.begin();
    while (itr != _objects.end()) {
        delete itr->second;
        itr++;
    }
}

void VisibleObjectManager::add(std::string name, VisibleObject *object) {
    _objects.insert(std::pair<std::string, VisibleObject*>(name, object));
}

void VisibleObjectManager::remove(std::string name) {
    auto results = _objects.find(name);
    if (results != _objects.end()) {
        delete results->second;
        _objects.erase(results);
    }
}

VisibleObject *VisibleObjectManager::get(std::string name) {
    auto results = _objects.find(name);
    if (results == _objects.end()) return NULL;
    return results->second;
}

void VisibleObjectManager::handleInputAll(sf::Event *event) {
    auto itr = _objects.begin();
    while (itr != _objects.end()) {
        if (itr->first == "test") { itr++; continue; }
        itr->second->handleInput(event);
        itr++;
    }
}

void VisibleObjectManager::updateAll(float timeElapsed) {
    auto itr = _objects.begin();
    while (itr != _objects.end()) {
        itr->second->update(timeElapsed);
        itr++;
    }

    // Detect collision. This could be improved in a lot of way but give us a starting point
    auto originItr = _objects.begin();
    while (originItr != _objects.end()) {
        sf::Rect<float> originBound = originItr->second->getBoundingRect();

        auto targetItr = _objects.begin();
        while (targetItr != _objects.end()) {
            if (targetItr == originItr) { targetItr++; continue; }
            sf::Rect<float> targetBound = targetItr->second->getBoundingRect();
            if (originBound.intersects(targetBound)) {
                originItr->second->collideWith(targetItr->second);
            }
            targetItr++;
        }
        originItr++;
    }
}

void VisibleObjectManager::drawAll(sf::RenderWindow *window) {
    auto itr = _objects.begin();
    while (itr != _objects.end()) {
        itr->second->draw(window);
        itr++;
    }
}


