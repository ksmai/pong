#ifndef _TEXT_H_
#define _TEXT_H_

#include <SDL.h>
#include <SDL_ttf.h>

class Text {
public:
  enum class Size {
    Small, Medium, Large
  };

  Text(SDL_Renderer *renderer, int small_size = 16, int medium_size = 32, int large_size = 64); 
  ~Text();
  void add_centered(const char *text, int x, int y, Size size, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void add(const char *text, int x, int y, Size size, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void add_centered(const char *text, int x, int y, Size size, SDL_Color color);
  void add(const char *text, int x, int y, Size size, SDL_Color color);
private:
  SDL_Renderer *renderer;
  int small_font_size;
  int medium_font_size;
  int large_font_size;
  TTF_Font *small_font;
  TTF_Font *medium_font;
  TTF_Font *large_font;
};

#endif
