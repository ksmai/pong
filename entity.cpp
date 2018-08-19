#include "graphics.h"
#include "entity.h"

Entity::Entity(Graphics *graphics, double x, double y):
  graphics(graphics),
  x(x),
  y(y) {
}

Entity::~Entity() {
}
