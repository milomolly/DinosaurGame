#ifndef TEXTURE_H
#define TEXTURE_H

#include<string>
#include<SDL.h>
#include<map>
using namespace std;

class Texture
{
    public:
        static Texture* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Texture();
        } //Hàm con trỏ duy nhất của class, dùng để chạy suốt chương trình

        bool Load(string id, string filename);  //Load texture
        void Drop(string id);   //Drop texture
        void Clean();   //Clean monitor

        void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE); //Vẽ Animation
        void Draw_1(SDL_Renderer *renderer, SDL_Rect r, std::string path);
        void DrawFrame(string id, int x, int y, int width, int height, int row, int frame, int jumpspeed, SDL_RendererFlip flip = SDL_FLIP_NONE ); // Vẽ ảnh chuyển động
        void DrawObstacles(string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);

        int loop=0;

        int m_loop = 0;

        int speed_loop = 0;

    private:
        Texture(){}
        map<string, SDL_Texture*> m_TextureMap; //Lưu id của texture
        static Texture* s_Instance;

};

#endif // TEXTURE_H
