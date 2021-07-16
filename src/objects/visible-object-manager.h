#ifndef PANG_VISIBLE_OBJECT_MANAGER_H
#define PANG_VISIBLE_OBJECT_MANAGER_H

#include <SFML/Graphics.hpp>
#include "visible-object.h"

class VisibleObjectManager {
public:
  ~VisibleObjectManager();
  void add(std::string name, VisibleObject *object);
  void remove(std::string name);
  VisibleObject *get(std::string name);

  void handleInputAll(sf::Event *event);
  void updateAll(float timeElapsed);
  void drawAll(sf::RenderWindow *window);

private:
  std::map<std::string, VisibleObject*> _objects;
};

#endif