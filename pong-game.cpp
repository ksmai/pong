#include <SDL.h>

#include "game.h"
#include "pong-game.h"
#include "paddle.h"
#include "constants.h"

PongGame::PongGame():
  Game(),
  player_score(0),
  computer_score(0),
  player_serving(true),
  playing(false),
  scored(false) {
  player = new Paddle(
    graphics,
    (constants::WINDOW_WIDTH - constants::PADDLE_WIDTH) / 2,
    constants::PLAYER_Y,
    constants::PADDLE_WIDTH,
    constants::PADDLE_HEIGHT,
    constants::PADDLE_SPEED
  );
  computer = new Paddle(
    graphics,
    (constants::WINDOW_WIDTH - constants::PADDLE_WIDTH) / 2,
    constants::COMPUTER_Y,
    constants::PADDLE_WIDTH,
    constants::PADDLE_HEIGHT,
    constants::PADDLE_SPEED
  );
  ball = new Ball(
    graphics,
    constants::WINDOW_WIDTH / 2,
    constants::WINDOW_HEIGHT / 2,
    constants::BALL_RADIUS
  );
}

PongGame::~PongGame() {
  delete ball;
  delete computer;
  delete player;
}

void PongGame::update(int dt) {
  player->update(dt);
  computer->update(dt);
  ball->update(dt);
}

void PongGame::render_impl() {
  player->render();
  computer->render();
  ball->render();
}

int PongGame::handle_event_impl() {
  if (keys_down[SDLK_LEFT]) {
    player->set_direction(Paddle::Direction::Left);
  } else if (keys_down[SDLK_RIGHT]) {
    player->set_direction(Paddle::Direction::Right);
  } else {
    player->set_direction(Paddle::Direction::None);
  }
  if (!playing && keys_down[SDLK_RETURN]) {
    playing = true;
  }
  return 0;
}
