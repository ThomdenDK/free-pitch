#pragma once

class State;

class IFreePitch {
    public:
        virtual void Run() = 0;
        virtual IWindow& GetWindow() = 0;
        virtual void ChangeState(State* state) = 0;
};