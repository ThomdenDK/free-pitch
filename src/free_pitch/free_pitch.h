#pragma once
#include "i_free_pitch.h"

class IWindow;

class FreePitch : IFreePitch {
    private:
        IWindow& window;
    public:
        FreePitch(IWindow& window);
        void Run() override;
};