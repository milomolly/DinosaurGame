#ifndef COLLISION_H
#define COLLISION_H

#include <SDL.h>

#include "Doctor.h"

class Collision
{
    public:
        bool check_Collision(SDL_Rect a, SDL_Rect b);

        static Collision* GetCollision(){
            return s_Collision = (s_Collision != nullptr)? s_Collision : new Collision();
        }
    private:
        Collision()
        {

        }
        static Collision* s_Collision;
};

#endif // COLLISION_H
