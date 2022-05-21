#include "Engine.h";
using namespace std;

int frame_start, frame_cur;

int main(int argc, char* argv[])
{
    Engine::GetInstance()->Init();

    while( Engine::GetInstance()->IsRunning())
    {
        frame_start = SDL_GetTicks();

        Engine::GetInstance()->Envents();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        frame_cur = SDL_GetTicks()-frame_start;
        if(frame_cur < Engine::GetInstance()->timeperframe()){
            SDL_Delay(Engine::GetInstance()->timeperframe() - frame_cur);
        }

    }



    //Engine::GetInstance()->Clean();
    return 0;
}
