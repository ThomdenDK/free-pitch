#pragma once
#include "free_pitch/i_window.h"

class SDL_Renderer;
class SDL_Window;
class UI;

class Window : public IWindow {
    public:
        Window(int w, int h);
        void Open() override;
        void Close() override;
        void Render() override;
        void DrawUI(UI& ui) override;
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
};