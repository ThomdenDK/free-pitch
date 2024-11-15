#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <memory>
#include "state.h"

class UIClickable;

class MainMenu : public State {
    public:
        MainMenu();
        void HandleEvent(SDL_Event& event) override;
};