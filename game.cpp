#include <SDL.h>

#include "game.h"
#include "text.h"
#include "constants.h"

Game::Game() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(
    constants::WINDOW_TITLE,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    constants::WINDOW_WIDTH,
    constants::WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
  );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  last_frame_time = SDL_GetTicks();
  text = new Text(renderer);
}

Game::~Game() {
  delete text;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int Game::run() {
  event_loop();
  return 0;
}

void Game::update(int dt) {
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  render_impl();
  SDL_RenderPresent(renderer);
}

void Game::render_impl() {
  text->add("Hello small", 0, 0, Text::Size::Small, 255, 255, 255);
  text->add("Hello medium", 0, 100, Text::Size::Medium, 255, 255, 255);
  text->add("Hello large", 0, 200, Text::Size::Large, 255, 255, 255);
}

void Game::event_loop() {
  while (true) {
    if (SDL_PollEvent(&event)) {
      if (handle_event()) {
        break;
      }
    }
    int current_time = SDL_GetTicks();
    int dt = current_time - last_frame_time;
    update(dt);
    render();
    last_frame_time = current_time;
  }
}

int Game::handle_event() {
  if (event.type == SDL_QUIT) {
    return 1;
  } else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) {
    return 1;
  }
  return 0;
}
