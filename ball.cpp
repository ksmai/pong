#include "ball.h"
#include "entity.h"
#include "constants.h"

Ball::Ball(Graphics *graphics, double x, double y, int radius):
  Entity(graphics, x, y),
  radius(radius),
  speed_x(0),
  speed_y(0) {
}

Ball::~Ball() {
}

double Ball::get_y() const {
  return y;
}

void Ball::update(int dt) {
  x += speed_x * dt / 1000;
  y += speed_y * dt / 1000;
  if (x < 0) {
    x = 0;
    speed_x = -speed_x;
  } else if (x > constants::WINDOW_WIDTH - radius) {
    x = constants::WINDOW_WIDTH - radius;
    speed_x = -speed_x;
  }
}

void Ball::render() {
  graphics->circle(x, y, radius, 255, 255, 255);
}

void Ball::set_speed(double speed_x, double speed_y) {
  this->speed_x = speed_x;
  this->speed_y = speed_y;
}

void Ball::set_position(double x, double y) {
  this->x = x;
  this->y = y;
}
