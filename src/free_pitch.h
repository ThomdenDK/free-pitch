#pragma once

class State;
class Window;

class FreePitch {
    private:
        State* state;
        Window* window;
    public:
        void Run();
        void ChangeState(State* state);
};