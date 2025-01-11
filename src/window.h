#pragma once

class SDL_Renderer;
class SDL_Window;
class State;

class Window {
    public:
        void Open(int w, int h);
        void Close();
        void Render();
        void Draw(State& state);
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
};