#include "computer_ai.h"
#include "paddle.h"
#include "ball.h"

ComputerAI::ComputerAI(Paddle *paddle, Ball *ball):
  paddle(paddle),
  ball(ball),
  last_direction(Paddle::Direction::None) {
}

Paddle::Direction ComputerAI::next_move() {
  double paddle_center = paddle->get_x() + paddle->get_w() / 2;
  double ball_center = ball->get_x();
  if (last_direction == Paddle::Direction::Left && ball_center < paddle_center) {
    return last_direction;
  } else if (last_direction == Paddle::Direction::Right && ball_center > paddle_center) {
    return last_direction;
  } else {
    double paddle_one_fifth = paddle->get_x() + paddle->get_w() / 5;
    double paddle_four_fifth = paddle->get_x() + paddle->get_w() * 4 / 5;
    if (ball_center < paddle_one_fifth) {
      return Paddle::Direction::Left;
    } else if (ball_center > paddle_four_fifth) {
      return Paddle::Direction::Right;
    } 
  }

  return Paddle::Direction::None;
}
