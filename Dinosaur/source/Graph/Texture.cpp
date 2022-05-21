#include "Texture.h"
#include "Engine.h"

#include<iostream>
using namespace std;

Texture* Texture::s_Instance = nullptr;

bool Texture::Load(string id, string filename)  //  Kiểm tra load img
{


    SDL_Surface* surface = IMG_Load(filename.c_str());


    if( surface == nullptr){
        SDL_Log("Fail to load texture : %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);

    if(texture == nullptr){
        SDL_Log("Fail to create texture from surface: %s, %s", filename.c_str(), SDL_GetError());
        return false;

    }

    m_TextureMap[id] = texture;
    return true;
}

void Texture::Drop(string id)
{
    SDL_DestroyTexture( m_TextureMap[id]  ); //Xóa texture khi không cần thiết
    m_TextureMap.erase(id);
}

void Texture::Clean()
{
    map<string, SDL_Texture*>::iterator it;
    for(it = m_TextureMap.begin(); it!=m_TextureMap.end(); ++it){
        SDL_DestroyTexture(it->second);
    } //Xóa tất cả các texture có trong map
    m_TextureMap.clear();
    SDL_Log("texture map cleanned!!!");
}

void Texture::Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{

    SDL_Rect srcRect = {loop, 0, width, height}; //Phần của img muốn xuất

    SDL_Rect dstRect = {x, y, width, height}; //Vị trí hiển thị trên mh

    loop-=4 + speed_loop;

    //cout<<srcRect.x<<' '<<srcRect.y<<' '<<widht<<' '<<height<<'\n';

    SDL_Rect srcRect2 = {srcRect.x+SCREEN_WIDTH, 0, width, height};


    if(srcRect.x <= -SCREEN_WIDTH) loop=0;

    //cout<<cnt;

    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &dstRect, &srcRect, 0, nullptr, flip);
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &dstRect, &srcRect2, 0, nullptr, flip);
}

void Texture::Draw_1(SDL_Renderer *renderer, SDL_Rect r, std::string path)
{
    SDL_RenderCopy(renderer, m_TextureMap[path], NULL, &r);

}

void Texture::DrawFrame(string id, int x, int y, int width, int height, int row, int frame, int jumpspeed, SDL_RendererFlip flip ){
    SDL_Rect srcRect = {width * frame, height*row, width, height}; //Phần của img muốn xuất



    SDL_Rect dstRect = {x , y - ( 210 - jumpspeed) , width, height}; //Vị trí hiển thị trên mh

    Engine::GetInstance()->Rect_id[id] = dstRect;


    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);

}

void Texture::DrawObstacles(string id, int x, int y, int width, int height, SDL_RendererFlip flip){
    SDL_Rect srcRect = {x + m_loop , y, width, height}; //Phần của img muốn xuất

    m_loop -= 4 + speed_loop;

    SDL_Rect dstRect = {0 , 0, width, height}; //Vị trí hiển thị trên mh

    Engine::GetInstance()->Rect_id[id] = srcRect;


    if(abs(m_loop) > 2000) m_loop =0;



    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &dstRect, &srcRect, 0, nullptr, flip);

}

