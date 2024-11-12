#pragma once
#include <SDL2/SDL.h>
#include <vector>

class UIElement;

class State {
    private:
        std::vector<UIElement*> UI_elements;
    public:
        virtual void HandleEvent(SDL_Event& event) = 0;
        int HandleAllEvents();
        std::vector<UIElement*> GetUIElements();
};