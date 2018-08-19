#ifndef _COMPUTER_AI_H_
#define _COMPUTER_AI_H_

#include "paddle.h"
#include "ball.h"

class ComputerAI {
public:
  ComputerAI(Paddle *paddle, Ball *ball);
  Paddle::Direction next_move();
private:
  Paddle *paddle;
  Ball *ball;
  Paddle::Direction last_direction;
};

#endif
