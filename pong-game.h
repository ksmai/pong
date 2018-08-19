#ifndef _PONG_GAME_H_
#define _PONG_GAME_H_

#include "game.h"
#include "paddle.h"

class PongGame: public Game {
public:
  PongGame();
  virtual ~PongGame() override;
protected:
  virtual void update(int dt) override;
  virtual void render_impl() override;
  virtual int handle_event_impl() override;
private:
  Paddle *player;
};

#endif
