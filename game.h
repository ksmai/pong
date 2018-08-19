#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>

class Game {
public:
  Game();
  virtual ~Game();
  virtual int run() final;
private:
  virtual void update(int dt);
  virtual void render() final;
  virtual void render_impl();
  virtual void event_loop() final;
  virtual int handle_event();
protected:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;
  int last_frame_time;
};

#endif