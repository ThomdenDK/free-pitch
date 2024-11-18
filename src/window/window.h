#pragma once
#include <string>
#include <memory>
#include "free_pitch/i_window.h"

class UIElement;
class SDL_Rect;
class SDL_Color;
class SDL_Renderer;
class SDL_Window;
class State;

class Window : public IWindow {
    public:
        void Open() override;
        void Close() override;
        void Render() override;
        void GetSize(int* w, int* h) override;
        void DrawStateContents(State& state) override;
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
};