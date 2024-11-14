#pragma once
#include <string>
#include <memory>
#include "free_pitch/i_window.h"

class UIElement;
class SDL_Rect;
class SDL_Color;
class State;

class Window : public IWindow {
    public:
        void Open();
        void Close();
        void Render();
        void DrawStateContents(State& state);
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
        void Draw(UIElement& obj);
};