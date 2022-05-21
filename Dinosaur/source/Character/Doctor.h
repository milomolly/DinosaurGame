#ifndef DOCTOR_H
#define DOCTOR_H

#include"Character.h"

class Doctor: public Character
{
    public:
        Doctor( Properties* props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);

        void Jump();
        int m_Jumpspeed, m_timespeed, stt;

    private:
        int m_Row, m_Frame, m_FrameCount;
        int m_Charspeed;
};

#endif // DOCTOR_H

