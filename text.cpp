#include <sstream>
#include <stdexcept>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "text.h"
#include "constants.h"

Text::Text(SDL_Renderer *renderer, int small_size, int medium_size, int large_size):
  renderer(renderer),
  small_font_size(small_size),
  medium_font_size(medium_size),
  large_font_size(large_size)
{
  if (!TTF_WasInit() && TTF_Init() == -1) {
    std::ostringstream err;
    err << "TTF_Init: " << TTF_GetError();
    throw std::runtime_error(err.str());
  }
  small_font = TTF_OpenFont(constants::FONT_FILENAME, small_font_size);
  medium_font = TTF_OpenFont(constants::FONT_FILENAME, medium_font_size);
  large_font = TTF_OpenFont(constants::FONT_FILENAME, large_font_size);
}

Text::~Text() {
  TTF_CloseFont(large_font);
  TTF_CloseFont(medium_font);
  TTF_CloseFont(small_font);
  TTF_Quit();
}

void Text::add(const char *text, int x, int y, Size size, SDL_Color color) {
  SDL_Surface *surface;
  if (size == Size::Small) {
    surface = TTF_RenderText_Solid(small_font, text, color);
  } else if (size == Size::Medium) {
    surface = TTF_RenderText_Solid(medium_font, text, color);
  } else if (size == Size::Large) {
    surface = TTF_RenderText_Solid(large_font, text, color);
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  int w;
  int h;
  SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  dest.w = w;
  dest.h = h;
  SDL_RenderCopy(renderer, texture, nullptr, &dest);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

void Text::add_centered(const char *text, int x, int y, Size size, SDL_Color color) {
  SDL_Surface *surface;
  if (size == Size::Small) {
    surface = TTF_RenderText_Solid(small_font, text, color);
  } else if (size == Size::Medium) {
    surface = TTF_RenderText_Solid(medium_font, text, color);
  } else if (size == Size::Large) {
    surface = TTF_RenderText_Solid(large_font, text, color);
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  int w;
  int h;
  SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
  SDL_Rect dest;
  dest.x = x - w / 2;
  dest.y = y - h / 2;
  dest.w = w;
  dest.h = h;
  SDL_RenderCopy(renderer, texture, nullptr, &dest);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

void Text::add(const char *text, int x, int y, Size size, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  SDL_Color color;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  add(text, x, y, size, color);
}

void Text::add_centered(const char *text, int x, int y, Size size, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  SDL_Color color;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  add_centered(text, x, y, size, color);
}
