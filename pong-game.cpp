#include <SDL.h>

#include "game.h"
#include "pong-game.h"
#include "paddle.h"
#include "constants.h"

PongGame::PongGame(): Game() {
  player = new Paddle(
    graphics,
    (constants::WINDOW_WIDTH - constants::PADDLE_WIDTH) / 2,
    constants::PLAYER_Y,
    constants::PADDLE_WIDTH,
    constants::PADDLE_HEIGHT,
    constants::PADDLE_SPEED
  );
}

PongGame::~PongGame() {
  delete player;
}

void PongGame::update(int dt) {
  player->update(dt);
}

void PongGame::render_impl() {
  player->render();
}

int PongGame::handle_event_impl() {
  if (keys_down[SDLK_LEFT]) {
    player->set_direction(Paddle::Direction::Left);
  } else if (keys_down[SDLK_RIGHT]) {
    player->set_direction(Paddle::Direction::Right);
  } else {
    player->set_direction(Paddle::Direction::None);
  }
  return 0;
}
