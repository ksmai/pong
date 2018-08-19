#include <SDL.h>
#include <random>
#include <sstream>
#include <string>

#include "game.h"
#include "pong-game.h"
#include "paddle.h"
#include "constants.h"
#include "text.h"

PongGame::PongGame():
  Game(),
  player_score(0),
  computer_score(0),
  player_serving(true),
  playing(false),
  scored(true) {
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
  check_ball_collision();
  check_score();

  player->update(dt);
  computer->update(dt);
  ball->update(dt);
}

void PongGame::render_impl() {
  player->render();
  computer->render();
  if (scored) {
    std::string message;
    if (player_score >= 5) {
      message = "YOU WON!";
    } else if (computer_score >= 5) {
      message = "YOU LOST!";
    } else {
      std::ostringstream oss;
      oss << "     You  "
          << player_score
          << " : "
          << computer_score
          << "  Computer";
      message = oss.str();
    }
    text->add_centered(message.c_str(), constants::WINDOW_WIDTH / 2, constants::WINDOW_HEIGHT / 2, Text::Size::Large, 255, 255, 255);
  } else {
    ball->render();
  }
}

int PongGame::handle_event_impl() {
  if (keys_down[SDLK_LEFT]) {
    player->set_direction(Paddle::Direction::Left);
  } else if (keys_down[SDLK_RIGHT]) {
    player->set_direction(Paddle::Direction::Right);
  } else {
    player->set_direction(Paddle::Direction::None);
  }
  if (keys_down[SDLK_RETURN] || keys_down[SDLK_SPACE]) {
    if (scored) {
      if (player_score >= 5 || computer_score >= 5) {
        player_score = 0;
        computer_score = 0;
      } else {
        scored = false;
      }
      ball->set_position(constants::WINDOW_WIDTH / 2, constants::WINDOW_HEIGHT / 2);
    } else if (!playing) {
      playing = true;
      std::random_device rd;
      std::mt19937 mt(rd());
      std::uniform_int_distribution<int> dist(
        -constants::BALL_SPEED_X_MAX / 2,
        constants::BALL_SPEED_X_MAX / 2
      );
      int ball_speed_x = dist(mt);
      int ball_speed_y = player_serving ? -constants::BALL_SPEED_Y : constants::BALL_SPEED_Y;
      ball->set_speed(ball_speed_x, ball_speed_y);
    }
  }
  return 0;
}

void PongGame::check_ball_collision() {
}

void PongGame::check_score() {
  if (scored || !playing) {
    return;
  }
  double ball_y = ball->get_y();
  if (ball_y < -constants::BALL_RADIUS) {
    player_score++;
    scored = true;
    playing = false;
    ball->set_speed(0, 0);
    player_serving = false;
  } else if (ball_y > constants::WINDOW_HEIGHT + constants::BALL_RADIUS) {
    computer_score++;
    scored = true;
    playing = false;
    ball->set_speed(0, 0);
    player_serving = true;
  }
}
