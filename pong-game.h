#ifndef _PONG_GAME_H_
#define _PONG_GAME_H_

#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "computer_ai.h"

class PongGame: public Game {
public:
  PongGame();
  virtual ~PongGame() override;
protected:
  virtual void update(int dt) override;
  virtual void render_impl() override;
  virtual int handle_event_impl() override;
private:
  void check_ball_collision();
  void check_score();

  Paddle *player;
  Paddle *computer;
  Ball *ball;
  ComputerAI *ai;
  int player_score;
  int computer_score;
  bool player_serving;
  bool playing;
  bool scored;
};

#endif
