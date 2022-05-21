#include "ttf.h"

void Drawscore::Text(SDL_Renderer *renderer, SDL_Rect r, std::string sentence, std::string path, int fontSize, SDL_Color c)
{
  TTF_Font *font = TTF_OpenFont(path.c_str(), fontSize);

  SDL_Surface *surface = TTF_RenderText_Solid(font, sentence.c_str(), c);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

  int w, h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  int x = r.x + r.w / 2 - w / 2, y = r.y + r.h / 2 - h / 2;
  SDL_Rect rText = {x, y, w, h};

  SDL_FreeSurface(surface);
  SDL_RenderCopy(renderer, texture, NULL, &rText);

  TTF_CloseFont(font);
}
