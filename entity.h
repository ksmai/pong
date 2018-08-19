#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "graphics.h"

class Entity {
public:
  Entity(Graphics *graphics, double x, double y);
  virtual ~Entity();
  virtual void update(int dt) = 0;
  virtual void render() = 0;
protected:
  Graphics *graphics;
  double x;
  double y;
};

#endif
