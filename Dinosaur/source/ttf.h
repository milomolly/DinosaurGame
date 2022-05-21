#ifndef TTF_H
#define TTF_H
#include<SDL.h>
#include<string>
#include<SDL_ttf.h>

namespace Drawscore{

  void Text(SDL_Renderer *renderer, SDL_Rect r, std::string sentence, std::string path, int fontSize, SDL_Color c);

}
#endif // TTF_H
