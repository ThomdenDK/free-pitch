#pragma once
#include <SDL2/SDL.h>
#include <vector>

class UIElement;
class UIClickable;

class State {
    public:
        virtual void HandleEvent(SDL_Event& event) = 0;
        std::vector<UIElement*> GetUIElements();
        std::vector<UIClickable*> GetUIClickables();
        int HandleAllEvents();
    protected:
        std::vector<UIElement*> ui_elements;
        std::vector<UIClickable*> ui_clickables;
};