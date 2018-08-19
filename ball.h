#ifndef _BALL_H_
#define _BALL_H_

#include "entity.h"
#include "graphics.h"

class Ball: public Entity {
public:
  Ball(Graphics *graphics, double x, double y, int radius);
  ~Ball();
  virtual void update(int dt) override;
  virtual void render() override;
  void set_speed(double speed_x, double speed_y);
  void set_position(double x, double y);
  double get_y() const;
private:
  int radius;
  double speed_x;
  double speed_y;
};

#endif
