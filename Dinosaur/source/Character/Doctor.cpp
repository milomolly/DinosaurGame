#include "Doctor.h"

#include"Texture.h"

#include<SDL.h>
#include"Engine.h"
Doctor::Doctor(Properties* props) : Character(props)
{
    m_FrameCount = 8;
    m_Row = 0;
    m_Charspeed = 80;
    m_Jumpspeed = 210;
    m_timespeed = 10;
}

void Doctor::Draw()
{
    Texture::GetInstance()->DrawFrame(m_TextureID,m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame, m_Jumpspeed );
}

void Doctor::Clean()
{
    Texture::GetInstance()->Clean();
}

void Doctor::Update(float dt)
{
        m_Charspeed = 80 - Texture::GetInstance()->speed_loop * 10;
        m_Frame = (SDL_GetTicks()/m_Charspeed) %m_FrameCount;

        if(stt == 1 && m_Jumpspeed >0 )
        {

        m_Frame =1;
        m_Jumpspeed -=m_timespeed;
        }
        if(stt == 1 && m_Jumpspeed == 0) stt=2;

        if(stt == 2 && m_Jumpspeed < 210)
        {
        m_Frame =1;
        m_Jumpspeed +=m_timespeed;
        }
        if(stt==2 && m_Jumpspeed == 210) stt=0;

}

void Doctor::Jump(){
    stt =1;

}

