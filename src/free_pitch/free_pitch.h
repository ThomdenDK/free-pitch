#pragma once
#include "i_free_pitch.h"

class IWindow;
class State;

class FreePitch : public IFreePitch {
    private:
        State& state;
        IWindow& window;
    public:
        FreePitch(IWindow& window, State& initial_state);
        void Run() override;
        void ChangeState(State& state) override;
};