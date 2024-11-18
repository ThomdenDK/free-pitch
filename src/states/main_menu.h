#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <memory>
#include "state.h"

class UIClickable;

class MainMenu : public State {
    public:
        MainMenu(IFreePitch* fp);
    private:
        void HandleEvent(SDL_Event& event) override;
        void HandleClick(int mx, int my, int ww, int wh) override;
};