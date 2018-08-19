#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "entity.h"
#include "graphics.h"

class Paddle: public Entity {
public:
  enum class Direction {
    None, Left, Right
  };

  Paddle(Graphics *graphics, double x, double y, int w, int h, double move_speed);
  virtual ~Paddle() override;
  virtual void update(int dt) override;
  virtual void render() override;
  void set_direction(Direction direction);
protected:
  const int w;
  const int h;
  const double move_speed;
  Direction direction;
};

#endif
