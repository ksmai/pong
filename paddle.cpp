#include <algorithm>

#include "graphics.h"
#include "entity.h"
#include "paddle.h"
#include "constants.h"

Paddle::Paddle(Graphics *graphics, double x, double y, int w, int h, double move_speed):
  Entity(graphics, x, y),
  w(w),
  h(h),
  move_speed(move_speed),
  direction(Direction::None) {
}

Paddle::~Paddle() {
}

double Paddle::get_x() const {
  return x;
}

double Paddle::get_y() const {
  return y;
}

int Paddle::get_w() const {
  return w;
}

int Paddle::get_h() const {
  return h;
}

void Paddle::set_direction(Direction direction) {
  this->direction = direction;
}

void Paddle::update(int dt) {
  if (direction == Direction::Left) {
    x = std::max(x - move_speed * dt / 1000, 0.0);
  } else if (direction == Direction::Right) {
    x = std::min(x + move_speed * dt / 1000, static_cast<double>(constants::WINDOW_WIDTH - w));
  }
}

void Paddle::render() {
  graphics->rectangle(x, y, w, h, 255, 255, 255);
}
