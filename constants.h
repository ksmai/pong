#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>

namespace constants {
  const int WINDOW_WIDTH = 640;
  const int WINDOW_HEIGHT = 480;
  std::string WINDOW_TITLE = "pong";

  const int PADDLE_WIDTH = 100;
  const int PADDLE_HEIGHT = 20;
  const int PADDLE_SPEED = 100;

  const int BALL_RADIUS = 5;
  const int BALL_SPEED_Y = 50;
  const int BALL_SPEED_X_MAX = 100;

  const int PLAYER_Y = 600;
  const int COMPUTER_Y = 20;

  const int MAX_SCORE = 5;
}

#endif
