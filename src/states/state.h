#pragma once
#include <SDL2/SDL.h>
#include <vector>

class UIElement;
class UIClickable;
class IWindow;
class IFreePitch;

class State {
    public:
        std::vector<UIElement*> GetUIElements();
        std::vector<UIClickable*> GetUIClickables();
        int HandleAllEvents(IWindow& window);
    protected:
        std::vector<UIElement*> ui_elements;
        std::vector<UIClickable*> ui_clickables;
        IFreePitch* free_pitch;
        virtual void HandleEvent(SDL_Event& event) = 0;
        virtual void HandleClick(int mx, int my, int ww, int wh) = 0;
};