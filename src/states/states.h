#pragma once
#include <SDL2/SDL.h>
#include <vector>

class UIElement;
class UIClickable;
class FreePitch;

class State {
    public:
        std::vector<UIElement*> GetUIElements();
        std::vector<UIClickable*> GetUIClickables();
        int HandleAllEvents();
        FreePitch* state_machine; 
    protected:
        std::vector<UIElement*> ui_elements;
        std::vector<UIClickable*> ui_clickables;
        virtual void HandleEvent(SDL_Event& event) {};
        void HandleClick(int mx, int my);
};

class MainMenu : public State {
    public:
        MainMenu();
};

class MinigameMenu : public State {
    public:
        MinigameMenu();
};