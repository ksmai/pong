#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

namespace constants {
  const int WINDOW_WIDTH = 1024;
  const int WINDOW_HEIGHT = 768;
  const char *const WINDOW_TITLE = "pong";

  const int PADDLE_WIDTH = 150;
  const int PADDLE_HEIGHT = 20;
  const int PADDLE_SPEED = 200;

  const int BALL_RADIUS = 10;
  const int BALL_SPEED_Y = 50;
  const int BALL_SPEED_X_MAX = 100;

  const int PLAYER_Y = 688;
  const int COMPUTER_Y = 60;

  const int MAX_SCORE = 5;

  const char *const FONT_FILENAME = "ARIAL.TTF";
}

#endif
