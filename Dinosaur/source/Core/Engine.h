#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 658

#include<map>

using namespace std;

class Engine
{
    public:
        static Engine* GetInstance(){
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
        } //Hàm con trỏ duy nhất của class, dùng để chạy suốt chương trình
        bool Init();
        bool Clean();
        void Quit();

        void Update(); //Update khi có input từ player
        void Render(); // Render ra đồ họa
        void Envents(); // Check thao tác từ player

        inline bool IsRunning(){ //Kiểm tra xem có chạy không
            return m_IsRunning;

        }

        inline SDL_Renderer* GetRenderer(){
            return m_Renderer;
        }

        int timeperframe();

        map<string, SDL_Rect> Rect_id;


    private:
        Engine(){}
        int m_IsRunning;

        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;

        int fps = 50;
        int cur_time = 0;

        static Engine* s_Instance;
};

#endif // ENGINE_H
