#include "Obs.h"

#include "Doctor.h"

#include"Texture.h"

#include<SDL.h>
#include"Engine.h"

Obs::Obs(Properties* props):Character(props)
{

}

void Obs::Draw()
{
    //cout<<m_Transform->X<<'\n';
    Texture::GetInstance()->DrawObstacles(m_TextureID,m_Transform->X, m_Transform->Y, m_Width, m_Height );
}

void Obs::Clean()
{
    Texture::GetInstance()->Clean();

}

void Obs::Update(float dt)
{

}
