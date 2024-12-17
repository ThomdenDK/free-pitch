#pragma once
#include "i_free_pitch.h"

class IWindow;
class State;

class FreePitch : public IFreePitch {
    private:
        State* state;
        IWindow& window;
    public:
        FreePitch(IWindow& window);
        void Run() override;
        void Run() override;
        void Run() override;
        IWindow& GetWindow() override;
        void ChangeState(State* state) override;
};