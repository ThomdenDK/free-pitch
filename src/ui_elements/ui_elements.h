#pragma once
#include <memory>
#include <functional>
#include <string>
#include <SDL2/SDL.h>

struct PropRect { float x, y, w, h; };

SDL_Rect PropToPixel(PropRect prop_rect, SDL_Renderer* renderer);

class UIElement {
    public:
        virtual void Draw(SDL_Renderer* renderer) = 0;
};

class UIClickable {
    public:
        virtual bool WasClicked(int mx, int my) = 0;
        virtual void ExecuteBehaviour() = 0;
};

class UIText : public UIElement {
    private:
        std::string str;
        SDL_Color color;
        SDL_Rect rect;
        bool auto_adjust_height;
    public:
        UIText(std::string str, SDL_Color color, SDL_Rect rect, bool auto_adjust_height);
        void Draw(SDL_Renderer* renderer) override;
};

class UIRect : public UIElement {
    private:
        SDL_Rect rect;
        SDL_Color color;
    public:
        UIRect(SDL_Rect rect, SDL_Color color);
        void Draw(SDL_Renderer* renderer) override;
        SDL_Rect GetRect();
};

class UIButton : public UIElement, public UIClickable {
    private:
        UIText text;
        UIRect rect;
        std::function<void()> behaviour;
    public:
        UIButton(std::string str, SDL_Color text_color, SDL_Color bkg_color, SDL_Rect rect, 
            std::function<void()> behaviour);
        void Draw(SDL_Renderer* renderer) override;
        bool WasClicked(int mx, int my) override;
        void ExecuteBehaviour() override;
};

