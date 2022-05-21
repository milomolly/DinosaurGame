#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<SDL.h>
#include <iostream>

class Vector2D
{
    public:
        float X,Y;
    public:
        Vector2D(float x =0, float y = 0): X(x), Y(y){}

    public:
        inline Vector2D operator+(const Vector2D&v){
            return Vector2D(X+v.X, Y+v.Y);
        }
        inline Vector2D operator-(const Vector2D&v){
            return Vector2D(X-v.X, Y-v.Y);
        }
        inline Vector2D operator*(float scalar){
            return Vector2D(X*scalar, Y*scalar);
        }

};

#endif // VECTOR2D_H
