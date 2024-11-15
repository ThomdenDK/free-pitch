#pragma once
class SDL_Renderer;
class IWindow;

class UIElement {
    public:
        virtual void Draw(SDL_Renderer* renderer) = 0;
};