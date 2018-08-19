#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <unordered_map>

#include "text.h"
#include "graphics.h"

class Game {
public:
  Game();
  virtual ~Game();
  virtual int run() final;
private:
  virtual void render() final;
  virtual void event_loop() final;
  virtual int handle_event() final;
protected:
  virtual void update(int dt);
  virtual void render_impl();
  virtual int handle_event_impl();

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;
  Text *text;
  Graphics *graphics;
  int last_frame_time;
  std::unordered_map<int, bool> keys_down;
};

#endif
