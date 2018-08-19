#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <SDL.h>

class Graphics {
public:
  Graphics(SDL_Renderer *renderer);
  ~Graphics();
  void circle(Sint16 x, Sint16 y, Sint16 radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void rectangle(Sint16 x, Sint16 y, Sint16 w, Sint16 h, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
private:
  SDL_Renderer *renderer;
};

#endif
