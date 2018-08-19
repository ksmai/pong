#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "graphics.h"

Graphics::Graphics(SDL_Renderer *renderer): renderer(renderer) {
}

Graphics::~Graphics() {
}

void Graphics::circle(Sint16 x, Sint16 y, Sint16 radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  filledCircleRGBA(renderer, x, y, radius, r, g, b, a);
}

void Graphics::rectangle(Sint16 x, Sint16 y, Sint16 w, Sint16 h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  boxRGBA(renderer, x, y, x + w, y + h, r, g, b, a);
}
