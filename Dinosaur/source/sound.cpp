#include "sound.h"
#include<SDL_mixer.h>


void Sound::open(std::string path, int loops)
{

  Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
  Mix_PlayChannel(-1, chunk, loops);
}
